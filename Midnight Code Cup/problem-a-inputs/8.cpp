#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Each trip is broken down into 1 or 2 legs to enforce strict branch isolation
struct Leg {
  int train_id, from, to;
};

struct Passenger {
  int id, u, v, t, pos;
  int current_leg = 0;
  vector<Leg> legs;
  bool in_transit = false, arrived = false;
};

struct Train {
  int id, pos, capacity, target_node = -1;
  vector<int> carrying;
};

int V, E, T_trains, C, N;
vector<vector<int>> adj;
vector<Passenger> passengers;
vector<Train> trains;

int dist_mat[100][100];
int next_node[100][100];
int node_to_branch[100]; // Maps a node to the ID of the train responsible for
                         // it

// Precompute shortest paths and next-steps for lightning-fast routing
void precompute() {
  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j)
      dist_mat[i][j] = 1e9;
    dist_mat[i][i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : adj[u]) {
        if (dist_mat[i][v] > dist_mat[i][u] + 1) {
          dist_mat[i][v] = dist_mat[i][u] + 1;
          q.push(v);
        }
      }
    }
  }
  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      if (i == j) {
        next_node[i][j] = i;
        continue;
      }
      for (int v : adj[i]) {
        if (dist_mat[v][j] == dist_mat[i][j] - 1) {
          next_node[i][j] = v;
          break;
        }
      }
    }
  }
}

// Maps the 30 subtrees (branches) and assigns 1 train per branch
void map_branches() {
  node_to_branch[1] = 0; // The Central Hub
  int train_idx = 0;
  for (int root : adj[1]) {
    train_idx++;
    queue<int> q;
    q.push(root);
    vector<int> vis(V + 1, 0);
    vis[1] = 1;
    vis[root] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      node_to_branch[u] = train_idx;
      for (int v : adj[u]) {
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  if (!(cin >> V >> E))
    return 0;
  adj.resize(V + 1);
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  precompute();
  map_branches();

  cin >> T_trains;
  trains.resize(T_trains);
  for (int i = 0; i < T_trains; ++i) {
    trains[i].id = i + 1;
    cin >> trains[i].pos;
  }

  cin >> C >> N;
  for (int i = 0; i < T_trains; ++i)
    trains[i].capacity = C;

  passengers.resize(N);
  for (int i = 0; i < N; ++i) {
    passengers[i].id = i + 1;
    cin >> passengers[i].u >> passengers[i].v >> passengers[i].t;
    passengers[i].pos = passengers[i].u;

    int bu = node_to_branch[passengers[i].u];
    int bv = node_to_branch[passengers[i].v];

    // Logical Routing: Break trips crossing the Hub into two distinct transfer
    // legs
    if (bu == bv) {
      passengers[i].legs.push_back({bu, passengers[i].u, passengers[i].v});
    } else if (bu == 0) {
      passengers[i].legs.push_back({bv, passengers[i].u, passengers[i].v});
    } else if (bv == 0) {
      passengers[i].legs.push_back({bu, passengers[i].u, passengers[i].v});
    } else {
      passengers[i].legs.push_back({bu, passengers[i].u, 1}); // Leg 1 to Hub
      passengers[i].legs.push_back({bv, 1, passengers[i].v}); // Leg 2 to Dest
    }
  }

  int current_tick = 1;
  int arrived_count = 0;
  vector<vector<string>> tick_actions(1), tick_moves(1);

  while (arrived_count < N) {
    vector<string> acts, moves;

    // --- 1. Drop Offs ---
    for (auto &t : trains) {
      if (!t.carrying.empty()) {
        vector<int> next_c;
        for (int pid : t.carrying) {
          Passenger &p = passengers[pid];
          if (t.pos == p.legs[p.current_leg].to) {
            acts.push_back("drop " + to_string(t.id) + " " + to_string(p.id));
            p.in_transit = false;
            p.pos = t.pos;
            p.current_leg++;
            if (p.current_leg == p.legs.size()) {
              p.arrived = true;
              arrived_count++;
            }
          } else {
            next_c.push_back(pid);
          }
        }
        t.carrying = next_c;
      }
    }

    // --- 2. Predictive Assignments & Pick Ups ---
    for (auto &t : trains) {
      if (t.carrying.size() < t.capacity) {
        for (int i = 0; i < N && t.carrying.size() < t.capacity; ++i) {
          Passenger &p = passengers[i];
          if (!p.arrived && !p.in_transit && p.t <= current_tick &&
              p.pos == t.pos) {
            if (p.legs[p.current_leg].train_id == t.id) {
              p.in_transit = true;
              t.carrying.push_back(i);
              acts.push_back("pick " + to_string(t.id) + " " + to_string(p.id));
            }
          }
        }
      }

      // Set Target using Deadheading heuristic
      if (!t.carrying.empty()) {
        t.target_node = passengers[t.carrying[0]]
                            .legs[passengers[t.carrying[0]].current_leg]
                            .to;
      } else {
        int best_time = 2e9, best_t = 2e9;
        t.target_node = -1;
        for (int i = 0; i < N; ++i) {
          Passenger &p = passengers[i];
          if (!p.arrived && !p.in_transit &&
              p.legs[p.current_leg].train_id == t.id) {
            // For Leg 2 transfers, p.t is safe to use since it guarantees
            // current_tick > p.t
            int arrival = max(current_tick + dist_mat[t.pos][p.pos], p.t);
            if (arrival < best_time || (arrival == best_time && p.t < best_t)) {
              best_time = arrival;
              best_t = p.t;
              t.target_node = p.pos;
            }
          }
        }
      }
    }

    // --- 3. Unrestricted Strict Movement ---
    for (auto &t : trains) {
      if (t.target_node != -1 && t.pos != t.target_node) {
        t.pos = next_node[t.pos][t.target_node];
        moves.push_back(to_string(t.id) + " " + to_string(t.pos));
      }
    }

    tick_actions.push_back(acts);
    tick_moves.push_back(moves);
    current_tick++;
  }

  int total_ticks = current_tick - 1;
  cout << total_ticks << "\n";
  for (int s = 1; s <= total_ticks; ++s) {
    cout << tick_actions[s].size() << "\n";
    for (const string &a : tick_actions[s])
      cout << a << "\n";
    cout << tick_moves[s].size() << "\n";
    for (const string &m : tick_moves[s])
      cout << m << "\n";
  }

  return 0;
}
