// #include <iostream>
// #include <queue>
// #include <set>
// #include <vector>
//
// using namespace std;
//
// struct Edge {
//   int to, id;
// };
//
// struct Tradesman {
//   int id, start, dest, spawn_time;
//   bool picked_up = false;
//   bool delivered = false;
// };
//
// struct Train {
//   int id, pos;
//   int capacity_left;
//   int target_city = -1;
//   vector<int> passengers;
// };
//
// int V, E;
// vector<vector<Edge>> adj;
// vector<vector<int>> dist_matrix;
// vector<int> city_demand;
//
// // Precompute All-Pairs Shortest Paths for O(1) routing
// void precompute_apsp() {
//   dist_matrix.assign(V + 1, vector<int>(V + 1, 1e9));
//   for (int start = 1; start <= V; ++start) {
//     queue<int> q;
//     q.push(start);
//     dist_matrix[start][start] = 0;
//
//     while (!q.empty()) {
//       int u = q.front();
//       q.pop();
//       for (const auto &edge : adj[u]) {
//         int v = edge.to;
//         if (dist_matrix[start][v] > dist_matrix[start][u] + 1) {
//           dist_matrix[start][v] = dist_matrix[start][u] + 1;
//           q.push(v);
//         }
//       }
//     }
//   }
// }
//
// // O(1) pathfinding step using the distance matrix
// int get_next_step(int current, int target) {
//   if (current == target)
//     return current;
//   int best_v = current;
//   int min_d = dist_matrix[target][current];
//
//   for (const auto &edge : adj[current]) {
//     int v = edge.to;
//     if (dist_matrix[target][v] < min_d) {
//       min_d = dist_matrix[target][v];
//       best_v = v;
//     }
//   }
//   return best_v;
// }
//
// int main() {
//   // Ultra-fast I/O
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   if (!(cin >> V >> E))
//     return 0;
//
//   adj.resize(V + 1);
//   for (int i = 0; i < E; ++i) {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back({v, i});
//     adj[v].push_back({u, i});
//   }
//
//   precompute_apsp();
//
//   int T;
//   cin >> T;
//   vector<Train> trains(T + 1);
//   for (int i = 1; i <= T; ++i) {
//     trains[i].id = i;
//     cin >> trains[i].pos;
//   }
//
//   int C, N;
//   cin >> C >> N;
//   for (int i = 1; i <= T; i++)
//     trains[i].capacity_left = C;
//
//   vector<Tradesman> tradesmen(N + 1);
//   for (int i = 1; i <= N; ++i) {
//     tradesmen[i].id = i;
//     cin >> tradesmen[i].start >> tradesmen[i].dest >>
//     tradesmen[i].spawn_time;
//   }
//
//   int tick = 1;
//   int delivered_count = 0;
//   int next_spawn_idx = 1;
//
//   vector<queue<int>> station_waiting(V + 1);
//   city_demand.assign(V + 1, 0);
//
//   struct OutputTick {
//     vector<string> actions;
//     vector<pair<int, int>> moves;
//   };
//   vector<OutputTick> timeline;
//
//   while (delivered_count < N) {
//     OutputTick current_out;
//     set<int> locked_edges;
//
//     // 1. Spawning Phase
//     while (next_spawn_idx <= N &&
//            tradesmen[next_spawn_idx].spawn_time == tick) {
//       station_waiting[tradesmen[next_spawn_idx].start].push(next_spawn_idx);
//       city_demand[tradesmen[next_spawn_idx].start]++;
//       next_spawn_idx++;
//     }
//
//     // 2. Drop-off and Pick-up Phase
//     for (int i = 1; i <= T; ++i) {
//       Train &tr = trains[i];
//
//       // Execute Drops
//       for (auto it = tr.passengers.begin(); it != tr.passengers.end();) {
//         int p_idx = *it;
//         if (tradesmen[p_idx].dest == tr.pos) {
//           current_out.actions.push_back("drop " + to_string(tr.id) + " " +
//                                         to_string(tradesmen[p_idx].id));
//           tradesmen[p_idx].delivered = true;
//           delivered_count++;
//           tr.capacity_left++;
//           it = tr.passengers.erase(it);
//         } else {
//           ++it;
//         }
//       }
//
//       // Clean station queue of stolen tradesmen
//       while (!station_waiting[tr.pos].empty() &&
//              tradesmen[station_waiting[tr.pos].front()].picked_up) {
//         station_waiting[tr.pos].pop();
//       }
//
//       // Execute Opportunistic Picks (up to capacity)
//       while (!station_waiting[tr.pos].empty() && tr.capacity_left > 0) {
//         int p_idx = station_waiting[tr.pos].front();
//         station_waiting[tr.pos].pop();
//
//         tradesmen[p_idx].picked_up = true;
//         city_demand[tr.pos]--;
//
//         tr.passengers.push_back(p_idx);
//         tr.capacity_left--;
//         current_out.actions.push_back("pick " + to_string(tr.id) + " " +
//                                       to_string(tradesmen[p_idx].id));
//       }
//     }
//
//     // 3. Target Re-evaluation & Commitment
//     vector<int> incoming_cap(V + 1, 0);
//
//     // Step 3a: Verify existing empty train commitments
//     for (int i = 1; i <= T; ++i) {
//       Train &tr = trains[i];
//       if (tr.passengers.empty() && tr.target_city != -1) {
//         // If demand is met by other incoming trains or picked up, cancel
//         // commitment
//         if (city_demand[tr.target_city] <= incoming_cap[tr.target_city]) {
//           tr.target_city = -1;
//         } else {
//           incoming_cap[tr.target_city] += tr.capacity_left;
//         }
//       }
//     }
//
//     // Step 3b: Assign new targets
//     for (int i = 1; i <= T; ++i) {
//       Train &tr = trains[i];
//
//       if (!tr.passengers.empty()) {
//         // Elevator routing to closest onboard destination
//         int best_v = -1, best_dist = 1e9;
//         for (int p_idx : tr.passengers) {
//           int d = dist_matrix[tr.pos][tradesmen[p_idx].dest];
//           if (d < best_dist) {
//             best_dist = d;
//             best_v = tradesmen[p_idx].dest;
//           }
//         }
//         tr.target_city = best_v;
//       } else if (tr.target_city == -1) {
//         // Empty train Gravity Dispatch
//         int best_v = -1;
//         double best_score = -1.0;
//
//         for (int v = 1; v <= V; ++v) {
//           if (city_demand[v] > incoming_cap[v]) {
//             int oldest_wait =
//                 tick - tradesmen[station_waiting[v].front()].spawn_time;
//             double dist = dist_matrix[tr.pos][v];
//
//             // Score formula balances distance, wait time, and unserved
//             demand double score =
//                 ((city_demand[v] - incoming_cap[v]) * (oldest_wait + 1)) /
//                 (dist * dist + 1.0);
//
//             if (score > best_score) {
//               best_score = score;
//               best_v = v;
//             }
//           }
//         }
//         if (best_v != -1) {
//           tr.target_city = best_v;
//           incoming_cap[best_v] += tr.capacity_left;
//         }
//       }
//     }
//
//     // 4. Collision-Free Movement Phase
//     for (int i = 1; i <= T; ++i) {
//       Train &tr = trains[i];
//       if (tr.target_city != -1 && tr.target_city != tr.pos) {
//         int nxt = get_next_step(tr.pos, tr.target_city);
//         if (nxt != tr.pos) {
//           int edge_id = -1;
//           // Find the edge ID for collision checking
//           for (const auto &edge : adj[tr.pos]) {
//             if (edge.to == nxt) {
//               edge_id = edge.id;
//               break;
//             }
//           }
//           // Lock the edge for this tick to prevent Beutsche Dahn collisions
//           if (edge_id != -1 &&
//               locked_edges.find(edge_id) == locked_edges.end()) {
//             locked_edges.insert(edge_id);
//             current_out.moves.push_back({tr.id, nxt});
//             tr.pos = nxt;
//           }
//         }
//       }
//     }
//
//     timeline.push_back(current_out);
//     tick++;
//
//     // Safety Break
//     if (tick > 200000)
//       break;
//   }
//
//   // Output formatting per BD rules
//   cout << timeline.size() << "\n";
//   for (const auto &t_data : timeline) {
//     cout << t_data.actions.size() << "\n";
//     for (const string &act : t_data.actions)
//       cout << act << "\n";
//     cout << t_data.moves.size() << "\n";
//     for (const auto &mv : t_data.moves)
//       cout << mv.first << " " << mv.second << "\n";
//   }
//
//   return 0;
// }
//
//
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Edge {
  int to, id;
};

struct Tradesman {
  int id, start, dest, spawn_time;
  bool picked_up = false;
  bool delivered = false;
  int assigned_train =
      -1; // NEW: Lock passengers before they are even picked up
};

struct Train {
  int id, pos;
  int capacity_left;
  int target_city = -1;
  int primary_dest = -1;
  vector<int> passengers;
};

int V, E;
vector<vector<Edge>> adj;
vector<vector<int>> dist_matrix;

// Precompute All-Pairs Shortest Paths (APSP)
void precompute_apsp() {
  dist_matrix.assign(V + 1, vector<int>(V + 1, 1e9));
  for (int start = 1; start <= V; ++start) {
    queue<int> q;
    q.push(start);
    dist_matrix[start][start] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (const auto &edge : adj[u]) {
        int v = edge.to;
        if (dist_matrix[start][v] > dist_matrix[start][u] + 1) {
          dist_matrix[start][v] = dist_matrix[start][u] + 1;
          q.push(v);
        }
      }
    }
  }
}

int get_next_step(int current, int target) {
  if (current == target)
    return current;
  int best_v = current;
  int min_d = dist_matrix[target][current];

  for (const auto &edge : adj[current]) {
    int v = edge.to;
    if (dist_matrix[target][v] < min_d) {
      min_d = dist_matrix[target][v];
      best_v = v;
    }
  }
  return best_v;
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
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  precompute_apsp();

  int T;
  cin >> T;
  vector<Train> trains(T + 1);
  for (int i = 1; i <= T; ++i) {
    trains[i].id = i;
    cin >> trains[i].pos;
  }

  int C, N;
  cin >> C >> N;
  for (int i = 1; i <= T; i++)
    trains[i].capacity_left = C;

  vector<Tradesman> tradesmen(N + 1);
  // Group tradesmen by their starting city for lightning-fast future lookahead
  vector<vector<int>> tradesmen_by_start(V + 1);

  for (int i = 1; i <= N; ++i) {
    tradesmen[i].id = i;
    cin >> tradesmen[i].start >> tradesmen[i].dest >> tradesmen[i].spawn_time;
    tradesmen_by_start[tradesmen[i].start].push_back(i);
  }

  int tick = 1;
  int delivered_count = 0;

  struct OutputTick {
    vector<string> actions;
    vector<pair<int, int>> moves;
  };
  vector<OutputTick> timeline;

  while (delivered_count < N) {
    OutputTick current_out;
    set<int> locked_edges;

    // 1. Spawning Phase
    for (int i = 1; i <= N; ++i) {
      // (We no longer need a strict station_waiting queue because we scan
      // tradesmen_by_start directly)
    }

    // 2. Drop-off and STRICT Sector Pick-up Phase
    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];

      // Execute Drops
      for (auto it = tr.passengers.begin(); it != tr.passengers.end();) {
        int p_idx = *it;
        if (tradesmen[p_idx].dest == tr.pos) {
          current_out.actions.push_back("drop " + to_string(tr.id) + " " +
                                        to_string(tradesmen[p_idx].id));
          tradesmen[p_idx].delivered = true;
          delivered_count++;
          tr.capacity_left++;
          it = tr.passengers.erase(it);
        } else {
          ++it;
        }
      }

      if (tr.passengers.empty()) {
        tr.primary_dest = -1; // Reset sector
      }

      // Opportunistic Sector-bounded Loading
      for (int p_idx : tradesmen_by_start[tr.pos]) {
        if (tr.capacity_left == 0)
          break;
        if (tradesmen[p_idx].picked_up || tradesmen[p_idx].spawn_time > tick)
          continue;

        // Don't steal passengers assigned to a train that is already arriving
        if (tradesmen[p_idx].assigned_train != -1 &&
            tradesmen[p_idx].assigned_train != tr.id)
          continue;

        bool board_passenger = false;

        if (tr.primary_dest == -1) {
          tr.primary_dest = tradesmen[p_idx].dest;
          board_passenger = true;
        }
        // Tighter sector threshold for dense graph
        else if (dist_matrix[tr.primary_dest][tradesmen[p_idx].dest] <= 6) {
          board_passenger = true;
        }

        if (board_passenger) {
          tradesmen[p_idx].picked_up = true;
          tradesmen[p_idx].assigned_train = tr.id;
          tr.passengers.push_back(p_idx);
          tr.capacity_left--;
          current_out.actions.push_back("pick " + to_string(tr.id) + " " +
                                        to_string(tradesmen[p_idx].id));
        }
      }
    }

    // 3. Predictive Gravity Dispatch
    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];

      if (!tr.passengers.empty()) {
        // Elevator routing
        int best_v = -1, best_dist = 1e9;
        for (int p_idx : tr.passengers) {
          int d = dist_matrix[tr.pos][tradesmen[p_idx].dest];
          if (d < best_dist) {
            best_dist = d;
            best_v = tradesmen[p_idx].dest;
          }
        }
        tr.target_city = best_v;
      } else if (tr.target_city == -1 || tr.target_city == tr.pos) {
        int best_v = -1;
        double best_score = -1.0;
        vector<int> best_pax_to_lock;

        // Evaluate all cities based on FUTURE demand
        for (int v = 1; v <= V; ++v) {
          double score = 0;
          int expected_pax = 0;
          int eta = tick + dist_matrix[tr.pos][v];
          vector<int> pax_to_lock;

          for (int p_idx : tradesmen_by_start[v]) {
            if (!tradesmen[p_idx].picked_up &&
                tradesmen[p_idx].assigned_train == -1) {
              // Can we get there roughly around the time they spawn? (Allow 3
              // tick buffer)
              if (tradesmen[p_idx].spawn_time <= eta + 3) {
                expected_pax++;
                int wait_time = max(0, eta - tradesmen[p_idx].spawn_time);
                score += (wait_time + 10); // Reward minimizing wait time
                pax_to_lock.push_back(p_idx);
                if (expected_pax == C)
                  break; // Train will be full
              }
            }
          }

          if (expected_pax > 0) {
            // Formula strongly heavily favors large clusters and short
            // distances
            score =
                (score * expected_pax) / pow(dist_matrix[tr.pos][v] + 1.0, 1.8);

            if (score > best_score) {
              best_score = score;
              best_v = v;
              best_pax_to_lock = pax_to_lock;
            }
          }
        }

        if (best_v != -1) {
          tr.target_city = best_v;
          // Lock the future passengers so other trains don't head to the exact
          // same spot
          for (int p_idx : best_pax_to_lock) {
            tradesmen[p_idx].assigned_train = tr.id;
          }
        }
      }
    }

    // 4. Movement Phase (Collision Free)
    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];
      if (tr.target_city != -1 && tr.target_city != tr.pos) {
        int nxt = get_next_step(tr.pos, tr.target_city);
        if (nxt != tr.pos) {
          int edge_id = -1;
          for (const auto &edge : adj[tr.pos]) {
            if (edge.to == nxt) {
              edge_id = edge.id;
              break;
            }
          }
          if (edge_id != -1 &&
              locked_edges.find(edge_id) == locked_edges.end()) {
            locked_edges.insert(edge_id);
            current_out.moves.push_back({tr.id, nxt});
            tr.pos = nxt;
          }
        }
      }
    }

    timeline.push_back(current_out);
    tick++;

    if (tick > 500000)
      break; // Hard Limit Timeout Break
  }

  // BD Formal File Generation
  cout << timeline.size() << "\n";
  for (const auto &t_data : timeline) {
    cout << t_data.actions.size() << "\n";
    for (const string &act : t_data.actions)
      cout << act << "\n";
    cout << t_data.moves.size() << "\n";
    for (const auto &mv : t_data.moves)
      cout << mv.first << " " << mv.second << "\n";
  }

  return 0;
}
