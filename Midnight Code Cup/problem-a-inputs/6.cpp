#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Passenger {
  int id, u, v, t;
  bool picked_up = false;
  bool arrived = false;
  int assigned_train = -1;
};

struct Train {
  int id, pos, capacity;
  vector<int> carrying;
  int target_p = -1;
  int target_node = -1;
};

int V, E, T_trains, C, N;
vector<vector<int>> adj;
vector<Passenger> passengers;
vector<Train> trains;

// Precomputed decoupled subgraphs
int dist_mat[11][115][115];
int next_node[11][115][115];

// A train is only allowed on Hubs (101-110) or its dedicated highway nodes
bool is_allowed(int u, int train_id) {
  if (u >= 101 && u <= 110)
    return true;
  if (u >= 1 && u <= 100) {
    return (u % 10) == (train_id % 10);
  }
  return false;
}

void precompute_highways() {
  for (int t = 1; t <= 10; ++t) {
    for (int i = 1; i <= V; ++i) {
      for (int j = 1; j <= V; ++j) {
        dist_mat[t][i][j] = 1e9;
        next_node[t][i][j] = -1;
      }
    }
    for (int i = 1; i <= V; ++i) {
      if (!is_allowed(i, t))
        continue;
      dist_mat[t][i][i] = 0;
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
          if (is_allowed(v, t) && dist_mat[t][i][v] > dist_mat[t][i][u] + 1) {
            dist_mat[t][i][v] = dist_mat[t][i][u] + 1;
            q.push(v);
          }
        }
      }
    }
    for (int i = 1; i <= V; ++i) {
      if (!is_allowed(i, t))
        continue;
      for (int j = 1; j <= V; ++j) {
        if (i == j || dist_mat[t][i][j] == 1e9)
          continue;
        for (int v : adj[i]) {
          if (is_allowed(v, t) && dist_mat[t][v][j] == dist_mat[t][i][j] - 1) {
            next_node[t][i][j] = v;
            break;
          }
        }
      }
    }
  }
}

int main() {
  // Ultra-fast I/O for 10,000+ lines
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
  }

  // Carve out the 10 disjoint parallel highways
  precompute_highways();

  int current_tick = 1;
  int arrived_count = 0;

  vector<vector<string>> tick_actions(1);
  vector<vector<string>> tick_moves(1);

  while (arrived_count < N) {
    vector<string> actions_this_tick;
    vector<string> moves_this_tick;

    // Phase 1: Unload Passengers
    for (auto &train : trains) {
      if (!train.carrying.empty()) {
        vector<int> next_carrying;
        for (int pid : train.carrying) {
          if (train.pos == passengers[pid - 1].v) {
            passengers[pid - 1].arrived = true;
            arrived_count++;
            actions_this_tick.push_back("drop " + to_string(train.id) + " " +
                                        to_string(pid));
          } else {
            next_carrying.push_back(pid);
          }
        }
        train.carrying = next_carrying;
        if (train.carrying.empty()) {
          train.target_p = -1;
          train.target_node = -1;
        }
      }
    }

    // Phase 2: Predictive Assignment & Boarding
    for (auto &train : trains) {
      if (train.target_p == -1 && train.carrying.empty()) {
        int best_p = -1;
        int best_time = 2e9;
        int best_t = 2e9;

        for (int i = 0; i < N; ++i) {
          if (!passengers[i].picked_up && !passengers[i].arrived &&
              passengers[i].assigned_train == -1) {
            int travel = dist_mat[train.id][train.pos][passengers[i].u];
            int pickup_time = max(current_tick + travel, passengers[i].t);

            // Tie-breaker: prioritize older passengers to maintain low overall
            // queue time
            if (pickup_time < best_time ||
                (pickup_time == best_time && passengers[i].t < best_t)) {
              best_time = pickup_time;
              best_t = passengers[i].t;
              best_p = i;
            }
          }
        }
        if (best_p != -1) {
          train.target_p = passengers[best_p].id;
          passengers[best_p].assigned_train = train.id;
          train.target_node = passengers[best_p].u;
        }
      }

      if (train.target_p != -1 && train.carrying.empty()) {
        int p_idx = train.target_p - 1;
        if (train.pos == passengers[p_idx].u &&
            current_tick >= passengers[p_idx].t) {

          passengers[p_idx].picked_up = true;
          train.carrying.push_back(passengers[p_idx].id);
          actions_this_tick.push_back("pick " + to_string(train.id) + " " +
                                      to_string(passengers[p_idx].id));
          train.target_node = passengers[p_idx].v;

          // Capacity Sweep: Grab anyone else going the exact same way
          for (int i = 0; i < N && train.carrying.size() < train.capacity;
               ++i) {
            if (!passengers[i].picked_up && !passengers[i].arrived &&
                passengers[i].assigned_train == -1 &&
                current_tick >= passengers[i].t) {
              if (passengers[i].u == train.pos &&
                  passengers[i].v == train.target_node) {
                passengers[i].assigned_train = train.id;
                passengers[i].picked_up = true;
                train.carrying.push_back(passengers[i].id);
                actions_this_tick.push_back("pick " + to_string(train.id) +
                                            " " + to_string(passengers[i].id));
              }
            }
          }
        }
      }
    }

    // Phase 3: Unrestricted Independent Movement
    for (auto &train : trains) {
      if (train.target_node != -1 && train.pos != train.target_node) {
        int next_pos = next_node[train.id][train.pos][train.target_node];
        train.pos = next_pos;
        moves_this_tick.push_back(to_string(train.id) + " " +
                                  to_string(next_pos));
      }
    }

    tick_actions.push_back(actions_this_tick);
    tick_moves.push_back(moves_this_tick);
    current_tick++;
  }

  int total_ticks = current_tick - 1;
  cout << total_ticks << "\n";
  for (int s = 1; s <= total_ticks; ++s) {
    cout << tick_actions[s].size() << "\n";
    for (const string &action : tick_actions[s])
      cout << action << "\n";
    cout << tick_moves[s].size() << "\n";
    for (const string &move : tick_moves[s])
      cout << move << "\n";
  }

  return 0;
}
