#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

// --- Data Structures ---

struct Passenger {
  int id;
  int u, v, t;
  bool picked_up = false;
  bool arrived = false;
  int train_assigned = -1; // -1 if not assigned
};

struct Train {
  int id;
  int pos;
  int capacity;
  vector<int> carrying;
  int target_passenger = -1;
  int target_node = -1;
  vector<int> path;
};

struct TickData {
  vector<string> actions; // pick and drop strings
  vector<string> moves;   // move strings
};

// --- Global Variables ---
int V, E, T, C, N;
vector<vector<int>> adj;
vector<Passenger> passengers;
vector<Train> trains;

// --- BFS Shortest Path ---
// Finds the shortest path from start to end avoiding collisions if needed.
// For this baseline, it simply finds the standard shortest path.
vector<int> bfs(int start, int end) {
  if (start == end)
    return {};

  vector<int> dist(V + 1, -1);
  vector<int> parent(V + 1, -1);
  queue<int> q;

  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (curr == end)
      break;

    for (int nxt : adj[curr]) {
      if (dist[nxt] == -1) {
        dist[nxt] = dist[curr] + 1;
        parent[nxt] = curr;
        q.push(nxt);
      }
    }
  }

  if (dist[end] == -1)
    return {}; // Failsafe for unreachable nodes

  vector<int> path;
  int curr = end;
  while (curr != start) {
    path.push_back(curr);
    curr = parent[curr];
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  // Optimize standard I/O operations for speed
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // 1. Read Graph
  if (!(cin >> V >> E))
    return 0;
  adj.resize(V + 1);
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // 2. Read Trains
  cin >> T;
  trains.resize(T);
  for (int i = 0; i < T; ++i) {
    trains[i].id = i + 1;
    cin >> trains[i].pos;
  }
  cin >> C;
  for (int i = 0; i < T; ++i) {
    trains[i].capacity = C;
  }

  // 3. Read Tradesmen (Passengers)
  cin >> N;
  passengers.resize(N);
  for (int i = 0; i < N; ++i) {
    passengers[i].id = i + 1;
    cin >> passengers[i].u >> passengers[i].v >> passengers[i].t;
  }

  // --- Simulation ---
  vector<TickData> output_history;
  int current_tick = 1;
  int arrived_count = 0;

  // Fast pointer to avoid scanning from 0 every tick
  int first_unassigned = 0;

  while (arrived_count < N && current_tick <= 1000000) {
    TickData current_output;

    // Phase A: Drop off passengers
    for (auto &train : trains) {
      if (!train.carrying.empty()) {
        vector<int> next_carrying;
        for (int p_id : train.carrying) {
          if (train.pos == passengers[p_id - 1].v) {
            passengers[p_id - 1].arrived = true;
            arrived_count++;
            current_output.actions.push_back("drop " + to_string(train.id) +
                                             " " + to_string(p_id));
          } else {
            next_carrying.push_back(p_id);
          }
        }
        train.carrying = next_carrying;

        // If everyone dropped off, train becomes idle
        if (train.carrying.empty()) {
          train.target_passenger = -1;
          train.target_node = -1;
        }
      }
    }

    // Phase B: Assign idle trains to waiting passengers
    for (auto &train : trains) {
      if (train.target_passenger == -1 && train.carrying.empty()) {
        int best_p = -1;
        for (int i = first_unassigned; i < N; ++i) {
          if (passengers[i].t <= current_tick && !passengers[i].picked_up &&
              passengers[i].train_assigned == -1) {
            best_p = i;
            break; // Greedily take the oldest waiting passenger
          }
        }

        if (best_p != -1) {
          train.target_passenger = passengers[best_p].id;
          passengers[best_p].train_assigned = train.id;
          train.target_node = passengers[best_p].u;
          train.path = bfs(train.pos, train.target_node);
        }
      }
    }

    // Update fast pointer to skip already assigned passengers
    while (first_unassigned < N &&
           passengers[first_unassigned].train_assigned != -1) {
      first_unassigned++;
    }

    // Phase C: Pick up passengers
    for (auto &train : trains) {
      if (train.target_passenger != -1 && train.carrying.empty()) {
        int p_idx = train.target_passenger - 1;

        if (train.pos == passengers[p_idx].u) {
          // Pick up the target
          passengers[p_idx].picked_up = true;
          train.carrying.push_back(passengers[p_idx].id);
          current_output.actions.push_back("pick " + to_string(train.id) + " " +
                                           to_string(passengers[p_idx].id));

          train.target_node = passengers[p_idx].v;

          // Capacity optimization: Group others at the same station going to
          // the same destination
          for (int i = first_unassigned;
               i < N && train.carrying.size() < train.capacity; ++i) {
            if (passengers[i].t <= current_tick &&
                passengers[i].train_assigned == -1 &&
                !passengers[i].picked_up) {
              if (passengers[i].u == train.pos &&
                  passengers[i].v == train.target_node) {
                passengers[i].train_assigned = train.id;
                passengers[i].picked_up = true;
                train.carrying.push_back(passengers[i].id);
                current_output.actions.push_back("pick " + to_string(train.id) +
                                                 " " +
                                                 to_string(passengers[i].id));
              }
            }
          }
          // Calculate path to destination
          train.path = bfs(train.pos, train.target_node);
        }
      }
    }

    // Phase D: Movement & Collision Handling
    set<pair<int, int>> used_edges;
    for (auto &train : trains) {
      if (!train.path.empty()) {
        int nxt = train.path.front();
        int u = min(train.pos, nxt);
        int v = max(train.pos, nxt);

        // Edge collision check
        if (used_edges.find({u, v}) == used_edges.end()) {
          used_edges.insert({u, v});
          train.pos = nxt;
          train.path.erase(train.path.begin());
          current_output.moves.push_back(to_string(train.id) + " " +
                                         to_string(nxt));
        }
      }
    }

    output_history.push_back(current_output);
    current_tick++;
  }

  // --- Output Results ---
  int total_ticks = output_history.size();
  cout << total_ticks << "\n";
  for (int s = 0; s < total_ticks; ++s) {
    cout << output_history[s].actions.size() << "\n";
    for (const string &action : output_history[s].actions)
      cout << action << "\n";

    cout << output_history[s].moves.size() << "\n";
    for (const string &move : output_history[s].moves)
      cout << move << "\n";
  }

  return 0;
}
