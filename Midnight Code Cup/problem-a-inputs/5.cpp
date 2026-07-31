#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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
vector<vector<int>> dist_mat;

// Precompute All-Pairs Shortest Paths for instantaneous heuristic distance
// lookups
void precompute_distances() {
  dist_mat.assign(V + 1, vector<int>(V + 1, 1e9));
  for (int i = 1; i <= V; ++i) {
    dist_mat[i][i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (int nxt : adj[curr]) {
        if (dist_mat[i][nxt] > dist_mat[i][curr] + 1) {
          dist_mat[i][nxt] = dist_mat[i][curr] + 1;
          q.push(nxt);
        }
      }
    }
  }
}

int main() {
  // Optimize standard I/O operations
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

  precompute_distances();

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

  int current_tick = 1;
  int arrived_count = 0;

  vector<vector<string>> tick_actions;
  vector<vector<string>> tick_moves;
  tick_actions.push_back({}); // 1-based index padding
  tick_moves.push_back({});

  while (arrived_count < N) {
    vector<string> actions_this_tick;
    vector<string> moves_this_tick;

    // --- Phase 1: Drops ---
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

    // --- Phase 2: Assignments & Pickups ---
    for (auto &train : trains) {
      // Predictive Deadheading Assignment
      if (train.target_p == -1 && train.carrying.empty()) {
        int best_p = -1;
        int best_pickup_time = 2e9;

        for (int i = 0; i < N; ++i) {
          if (!passengers[i].picked_up && !passengers[i].arrived &&
              passengers[i].assigned_train == -1) {
            int travel_time = dist_mat[train.pos][passengers[i].u];

            // Calculate the absolute earliest tick we could realistically pick
            // this person up
            int possible_pickup_tick =
                max(current_tick + travel_time, passengers[i].t);

            if (possible_pickup_tick < best_pickup_time) {
              best_pickup_time = possible_pickup_tick;
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

      // Pick up target and exact-destination carpoolers
      if (train.target_p != -1 && train.carrying.empty()) {
        int p_idx = train.target_p - 1;
        // Only pick up if the train has arrived AND the passenger has
        // officially spawned
        if (train.pos == passengers[p_idx].u &&
            current_tick >= passengers[p_idx].t) {

          passengers[p_idx].picked_up = true;
          train.carrying.push_back(passengers[p_idx].id);
          actions_this_tick.push_back("pick " + to_string(train.id) + " " +
                                      to_string(passengers[p_idx].id));
          train.target_node = passengers[p_idx].v;

          // Platform sweep for anyone else spawned and going the exact same way
          for (int i = 0; i < N && train.carrying.size() < train.capacity;
               ++i) {
            if (!passengers[i].picked_up && !passengers[i].arrived &&
                current_tick >= passengers[i].t) {
              if (passengers[i].u == train.pos &&
                  passengers[i].v == train.target_node &&
                  passengers[i].assigned_train == -1) {
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

    // --- Phase 3: Traffic Arbitration ---
    set<pair<int, int>> claimed_edges;

    vector<int> train_order;
    for (int i = 0; i < T_trains; ++i)
      train_order.push_back(i);

    // Give track priority to trains that are loaded
    sort(train_order.begin(), train_order.end(), [&](int a, int b) {
      return trains[a].carrying.size() > trains[b].carrying.size();
    });

    for (int t_idx : train_order) {
      auto &train = trains[t_idx];
      if (train.target_node != -1 && train.pos != train.target_node) {

        int best_next = -1;
        for (int nxt : adj[train.pos]) {
          if (dist_mat[nxt][train.target_node] <
              dist_mat[train.pos][train.target_node]) {
            best_next = nxt;
            break;
          }
        }

        if (best_next != -1) {
          int u = min(train.pos, best_next);
          int v = max(train.pos, best_next);

          // Trains can share nodes safely, but cannot cross the exact same edge
          // in the same tick
          if (claimed_edges.find({u, v}) == claimed_edges.end()) {
            claimed_edges.insert({u, v});
            train.pos = best_next;
            moves_this_tick.push_back(to_string(train.id) + " " +
                                      to_string(best_next));
          }
        }
      }
    }

    tick_actions.push_back(actions_this_tick);
    tick_moves.push_back(moves_this_tick);
    current_tick++;
  }

  // --- Output format for graded evaluation ---
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
