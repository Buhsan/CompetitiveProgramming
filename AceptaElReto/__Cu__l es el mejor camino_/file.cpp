#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val, dist, cnt;
};

int bfs (vector<vector<Node>> &adj, int ini, int dest, int n) {
  int res = 0;
  queue<Node> q;
  vector<bool> visited(n, false);
  visited[ini] = true;
  q.push({ini, 1, 0});

  while(!q.empty()) {
    Node curr = q.front();
    int val = curr.val;
    int curr_cnt = curr.cnt;
    q.pop();

    if (val == dest) {
      res = curr_cnt;
      break;
    }

    for (auto p : adj[val]) {
      int node = p.val;
      if (!visited[node]) {
        visited[node] = true;
        q.push({node, 1, curr_cnt+1});
      }
    }
  }

  return res;
}


pair<int, int> dijstra(vector<vector<Node>> &adj, int ini, int dest, int n) {
  priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)>> pq([](const Node &a, const Node &b) {
      return a.dist > b.dist;
  });
  vector<pair<int,int>> min_dist(n, {INT_MAX, 0});
  min_dist[ini] = {0,0};
  pq.push({ini, 0, 0});

  while(!pq.empty()) {
    Node curr = pq.top();
    int val = curr.val;
    int curr_dist = curr.dist;
    int curr_cnt = curr.cnt;
    pq.pop();

    // if (curr_dist > min_dist[ini].first) continue;

    for (auto p : adj[val]) {
      int node = p.val;
      int weight = p.dist;

      int newDist = curr_dist + weight;

      if (newDist < min_dist[node].first || (newDist == min_dist[node].first && curr_cnt+1 < min_dist[node].second)) {
        min_dist[node] = {newDist, curr_cnt+1};
        pq.push({node, newDist, curr_cnt+1});
      }
    }
  }

  return min_dist[dest];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  while(cin >> n >> m) {
    vector<vector<Node>> v(n);
    for (int i = 0; i < m; i++) {
      int a, b, c; cin >> a >> b >> c;
      a--; b--;
      v[a].push_back({b, c});
      v[b].push_back({a, c});
    }

    int k; cin >> k;

    for (int i = 0; i < k; i++) {
      int a, b; cin >> a >> b;
      a--; b--;
      auto p = dijstra(v, a, b, n);
      int mini = bfs(v, a, b, n);
      if (p.first == INT_MAX) {
        cout << "SIN CAMINO\n";
      }
      else {
        cout << p.first << " " << (p.second == mini ? "SI" : "NO") << '\n';
      }

    }
    cout << "----\n";
  }
  return 0;
}
