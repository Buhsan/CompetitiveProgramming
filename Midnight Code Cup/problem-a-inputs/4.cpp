// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <string>
// #include <vector>
//
// using namespace std;
//
// // --- Flow Network Structures ---
// struct Edge {
//   int v, cap, flow, rev;
// };
//
// int V, E, T_trains, C, N;
// vector<vector<Edge>> graph;
//
// // Safely adds directed edges to enforce strict edge capacities
// void add_dir_edge(int u, int v, int cap) {
//   graph[u].push_back({v, cap, 0, (int)graph[v].size()});
//   graph[v].push_back({u, 0, 0, (int)graph[u].size() - 1});
// }
//
// // --- Edmonds-Karp BFS ---
// int bfs(int s, int t, vector<int> &parent, vector<int> &parent_edge) {
//   fill(parent.begin(), parent.end(), -1);
//   queue<pair<int, int>> q;
//   q.push({s, 1e9});
//   parent[s] = -2;
//
//   while (!q.empty()) {
//     int u = q.front().first;
//     int flow = q.front().second;
//     q.pop();
//
//     for (int i = 0; i < graph[u].size(); i++) {
//       Edge &e = graph[u][i];
//       if (parent[e.v] == -1 && e.cap - e.flow > 0) {
//         parent[e.v] = u;
//         parent_edge[e.v] = i;
//         int new_flow = min(flow, e.cap - e.flow);
//         if (e.v == t)
//           return new_flow;
//         q.push({e.v, new_flow});
//       }
//     }
//   }
//   return 0;
// }
//
// // DFS to extract the raw city paths from the residual flow graph
// vector<int> current_path;
// bool dfs_extract(int u) {
//   if (u <= V)
//     current_path.push_back(u);
//   if (u == 2)
//     return true;
//
//   for (auto &e : graph[u]) {
//     if (e.flow > 0) {
//       e.flow--; // Consume the path
//       if (dfs_extract(e.v))
//         return true;
//       e.flow++; // Backtrack
//     }
//   }
//   if (u <= V)
//     current_path.pop_back();
//   return false;
// }
//
// // --- Schedule Structures ---
// struct PathInfo {
//   int id, length, next_avail_tick;
//   bool operator<(const PathInfo &other) const {
//     // Priority Queue is a max-heap; we invert the logic to minimize arrival
//     // time
//     int my_arr = next_avail_tick + length;
//     int other_arr = other.next_avail_tick + other.length;
//     if (my_arr != other_arr)
//       return my_arr > other_arr;
//     return next_avail_tick > other.next_avail_tick;
//   }
// };
//
// struct TrainSchedule {
//   int train_id, path_id, departure_tick;
// };
//
// struct InputEdge {
//   int u, v;
// };
//
// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//
//   if (!(cin >> V >> E))
//     return 0;
//
//   vector<InputEdge> input_edges(E + 1);
//   for (int i = 1; i <= E; ++i) {
//     cin >> input_edges[i].u >> input_edges[i].v;
//   }
//
//   // To prevent an undirected edge from being used in BOTH directions,
//   // we route it through a temporary capacity-constrained node.
//   int V_flow = V + 2 * E;
//   graph.resize(V_flow + 1);
//
//   for (int i = 1; i <= E; ++i) {
//     int u = input_edges[i].u;
//     int v = input_edges[i].v;
//     int in_node = V + 2 * i - 1;
//     int out_node = V + 2 * i;
//
//     add_dir_edge(in_node, out_node, 1); // Strict capacity limit of 1
//     add_dir_edge(u, in_node, 1);
//     add_dir_edge(out_node, v, 1);
//     add_dir_edge(v, in_node, 1);
//     add_dir_edge(out_node, u, 1);
//   }
//
//   // Ignore unused input
//   cin >> T_trains;
//   int dummy;
//   for (int i = 0; i < T_trains; ++i)
//     cin >> dummy;
//   cin >> C >> N;
//   for (int i = 0; i < N; ++i) {
//     cin >> dummy >> dummy >> dummy;
//   }
//
//   // 1. Compute Max Flow
//   int max_flow = 0;
//   vector<int> parent(V_flow + 1), parent_edge(V_flow + 1);
//   while (int flow = bfs(1, 2, parent, parent_edge)) {
//     max_flow += flow;
//     int curr = 2;
//     while (curr != 1) {
//       int p = parent[curr];
//       int idx = parent_edge[curr];
//       graph[p][idx].flow += flow;
//       graph[curr][graph[p][idx].rev].flow -= flow;
//       curr = p;
//     }
//   }
//
//   // 2. Extract strictly disjoint paths
//   vector<vector<int>> paths;
//   while (dfs_extract(1)) {
//     paths.push_back(current_path);
//     current_path.clear();
//   }
//
//   // 3. Optimal Mathematical Distribution
//   priority_queue<PathInfo> pq;
//   for (int i = 0; i < paths.size(); ++i) {
//     pq.push({i, (int)paths[i].size() - 1, 1});
//   }
//
//   vector<TrainSchedule> schedules;
//   for (int i = 1; i <= T_trains; ++i) {
//     PathInfo best = pq.top();
//     pq.pop();
//
//     schedules.push_back({i, best.id, best.next_avail_tick});
//     best.next_avail_tick++; // Pipeline the next train right behind it
//     pq.push(best);
//   }
//
//   // 4. Construct output history
//   vector<vector<string>> tick_actions(200000);
//   vector<vector<string>> tick_moves(200000);
//   int max_tick = 0;
//
//   for (const auto &sched : schedules) {
//     int t_id = sched.train_id;
//     int dep = sched.departure_tick;
//     const auto &p = paths[sched.path_id];
//     int L = p.size() - 1;
//
//     // Pick up exactly 3 unique passengers at Tick 1
//     int p_start = (t_id - 1) * 3 + 1;
//     tick_actions[1].push_back("pick " + to_string(t_id) + " " +
//                               to_string(p_start));
//     tick_actions[1].push_back("pick " + to_string(t_id) + " " +
//                               to_string(p_start + 1));
//     tick_actions[1].push_back("pick " + to_string(t_id) + " " +
//                               to_string(p_start + 2));
//
//     // Pipeline Movement
//     for (int step = 0; step < L; ++step) {
//       int tick = dep + step;
//       int nxt = p[step + 1];
//       tick_moves[tick].push_back(to_string(t_id) + " " + to_string(nxt));
//     }
//
//     // Drop off at destination
//     int arr = dep + L;
//     tick_actions[arr].push_back("drop " + to_string(t_id) + " " +
//                                 to_string(p_start));
//     tick_actions[arr].push_back("drop " + to_string(t_id) + " " +
//                                 to_string(p_start + 1));
//     tick_actions[arr].push_back("drop " + to_string(t_id) + " " +
//                                 to_string(p_start + 2));
//
//     max_tick = max(max_tick, arr);
//   }
//
//   // 5. Output for Grader
//   cout << max_tick << "\n";
//   for (int t = 1; t <= max_tick; ++t) {
//     cout << tick_actions[t].size() << "\n";
//     for (const string &a : tick_actions[t])
//       cout << a << "\n";
//     cout << tick_moves[t].size() << "\n";
//     for (const string &m : tick_moves[t])
//       cout << m << "\n";
//   }
//
//   return 0;
// }

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Edge {
  int to;
  int id; // To mark used edges
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int V, E;
  if (!(cin >> V >> E))
    return 0;

  vector<vector<Edge>> adj(V + 1);
  map<pair<int, int>, int> edge_id_map;

  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  int T, C, N;
  cin >> T;
  vector<int> train_start(T + 1);
  for (int i = 1; i <= T; ++i)
    cin >> train_start[i];

  cin >> C >> N;

  // We assume all tradesmen are 1 -> 2 based on the analysis
  for (int i = 0; i < N; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
  }

  // Find Edge-Disjoint Paths using greedy BFS
  vector<vector<int>> paths;
  vector<bool> used_edge(E, false);

  while (true) {
    vector<int> parent_node(V + 1, -1);
    vector<int> parent_edge(V + 1, -1);
    queue<int> q;

    q.push(1);
    parent_node[1] = 0; // Mark visited

    bool found = false;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      if (curr == 2) {
        found = true;
        break;
      }

      for (const auto &edge : adj[curr]) {
        if (!used_edge[edge.id] && parent_node[edge.to] == -1) {
          parent_node[edge.to] = curr;
          parent_edge[edge.to] = edge.id;
          q.push(edge.to);
        }
      }
    }

    if (!found)
      break; // No more disjoint paths available

    // Backtrack to build path
    vector<int> path;
    int curr = 2;
    while (curr != 1) {
      path.push_back(curr);
      used_edge[parent_edge[curr]] = true; // Mark edge as used globally
      curr = parent_node[curr];
    }
    // Path is backwards (2 -> ... -> 1), reverse it to get forward steps
    vector<int> forward_path;
    for (int i = path.size() - 1; i >= 0; --i) {
      forward_path.push_back(path[i]);
    }
    paths.push_back(forward_path);
  }

  // Emulate the routing
  int current_tick = 1;
  int tradesman_id = 1;
  queue<int> waiting_trains;
  for (int i = 1; i <= T; ++i)
    waiting_trains.push(i);

  // active_trains stores: {train_id, {path_index, current_step_index}}
  vector<pair<int, pair<int, int>>> active_trains;

  // Store outputs to format them later
  struct OutputTick {
    vector<string> actions;
    vector<pair<int, int>> moves;
  };
  vector<OutputTick> timeline;

  while (!waiting_trains.empty() || !active_trains.empty()) {
    OutputTick current_out;

    // 1. Pick/Drop Actions
    if (current_tick == 1) {
      // Load everyone at tick 1
      for (int tr = 1; tr <= T; ++tr) {
        for (int c = 0; c < C && tradesman_id <= N; ++c) {
          current_out.actions.push_back("pick " + to_string(tr) + " " +
                                        to_string(tradesman_id));
          tradesman_id++;
        }
      }
    }

    // Process drops for trains that reached the end in the previous tick
    vector<pair<int, pair<int, int>>> next_active;
    for (auto &t_info : active_trains) {
      int t_id = t_info.first;
      int p_idx = t_info.second.first;
      int step = t_info.second.second;

      if (step == paths[p_idx].size()) {
        // Reached destination! Drop passengers.
        int base_tradesman = (t_id - 1) * C + 1;
        for (int c = 0; c < C && (base_tradesman + c) <= N; ++c) {
          current_out.actions.push_back("drop " + to_string(t_id) + " " +
                                        to_string(base_tradesman + c));
        }
      } else {
        next_active.push_back(t_info);
      }
    }
    active_trains = next_active;

    // 2. Dispatch new trains
    for (size_t p = 0; p < paths.size() && !waiting_trains.empty(); ++p) {
      int t_id = waiting_trains.front();
      waiting_trains.pop();
      active_trains.push_back({t_id, {p, 0}});
    }

    // 3. Move active trains
    for (auto &t_info : active_trains) {
      int t_id = t_info.first;
      int p_idx = t_info.second.first;
      int step = t_info.second.second;

      int next_city = paths[p_idx][step];
      current_out.moves.push_back({t_id, next_city});

      // Advance train
      t_info.second.second++;
    }

    timeline.push_back(current_out);
    current_tick++;
  }

  // Print Results
  cout << timeline.size() << "\n";
  for (const auto &tick_data : timeline) {
    cout << tick_data.actions.size() << "\n";
    for (const string &action : tick_data.actions) {
      cout << action << "\n";
    }
    cout << tick_data.moves.size() << "\n";
    for (const auto &move : tick_data.moves) {
      cout << move.first << " " << move.second << "\n";
    }
  }

  return 0;
}
