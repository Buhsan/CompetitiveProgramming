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
};

struct Train {
  int id, pos;
  int capacity_left;
  int target_city = -1;
  vector<int> passengers;
};

int V, E;
vector<vector<Edge>> adj;
vector<vector<int>> dist_matrix;
vector<int> city_demand;

// Precompute All-Pairs Shortest Paths
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
  for (int i = 1; i <= N; ++i) {
    tradesmen[i].id = i;
    cin >> tradesmen[i].start >> tradesmen[i].dest >> tradesmen[i].spawn_time;
  }

  int tick = 1;
  int delivered_count = 0;
  int next_spawn_idx = 1;

  vector<queue<int>> station_waiting(V + 1);
  city_demand.assign(V + 1, 0);

  struct OutputTick {
    vector<string> actions;
    vector<pair<int, int>> moves;
  };
  vector<OutputTick> timeline;

  while (delivered_count < N) {
    OutputTick current_out;
    set<int> locked_edges;

    // 1. Spawning Phase
    while (next_spawn_idx <= N &&
           tradesmen[next_spawn_idx].spawn_time == tick) {
      station_waiting[tradesmen[next_spawn_idx].start].push(next_spawn_idx);
      city_demand[tradesmen[next_spawn_idx].start]++;
      next_spawn_idx++;
    }

    // 2. Drop-off and Pick-up Phase
    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];

      // Drop-offs
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

      while (!station_waiting[tr.pos].empty() &&
             tradesmen[station_waiting[tr.pos].front()].picked_up) {
        station_waiting[tr.pos].pop();
      }

      // Pick-ups (Aggressive filling)
      while (!station_waiting[tr.pos].empty() && tr.capacity_left > 0) {
        int p_idx = station_waiting[tr.pos].front();
        station_waiting[tr.pos].pop();

        tradesmen[p_idx].picked_up = true;
        city_demand[tr.pos]--;

        tr.passengers.push_back(p_idx);
        tr.capacity_left--;
        current_out.actions.push_back("pick " + to_string(tr.id) + " " +
                                      to_string(tradesmen[p_idx].id));
      }
    }

    vector<int> incoming_cap(V + 1, 0);

    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];
      if (tr.passengers.empty() && tr.target_city != -1) {
        if (city_demand[tr.target_city] <= incoming_cap[tr.target_city]) {
          tr.target_city = -1;
        } else {
          incoming_cap[tr.target_city] += tr.capacity_left;
        }
      }
    }

    for (int i = 1; i <= T; ++i) {
      Train &tr = trains[i];
      if (!tr.passengers.empty()) {
        int best_v = -1, best_dist = 1e9;
        for (int p_idx : tr.passengers) {
          int d = dist_matrix[tr.pos][tradesmen[p_idx].dest];
          if (d < best_dist) {
            best_dist = d;
            best_v = tradesmen[p_idx].dest;
          }
        }
        tr.target_city = best_v;
      } else if (tr.target_city == -1) {
        int best_v = -1;
        double best_score = -1.0;

        // Gravity dispatch favoring oldest waiting tradesmen
        for (int v = 1; v <= V; ++v) {
          if (city_demand[v] > incoming_cap[v]) {
            int oldest_wait =
                tick - tradesmen[station_waiting[v].front()].spawn_time;
            double dist = dist_matrix[tr.pos][v];
            double score =
                ((city_demand[v] - incoming_cap[v]) * (oldest_wait + 1)) /
                (dist * dist + 1.0);

            if (score > best_score) {
              best_score = score;
              best_v = v;
            }
          }
        }
        if (best_v != -1) {
          tr.target_city = best_v;
          incoming_cap[best_v] += tr.capacity_left;
        }
      }
    }

    // 4. Movement Phase
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

    if (tick > 50000)
      break; // Hard failsafe
  }

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
