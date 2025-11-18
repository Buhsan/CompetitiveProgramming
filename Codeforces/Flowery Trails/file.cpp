#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  int node, w;
};

unordered_set<int> visited;

void backtraking(vector<vector<pair<int, int>>> &prev, int value, ll &sum,
                 unordered_set<int> &visited) {
  if (value == 0)
    return;
  for (auto [destination, weight] : prev[value]) {
    sum += weight;
    if (!visited.count(destination)) {
      visited.insert(destination);
      backtraking(prev, destination, sum, visited);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(
      [](const Node &a, const Node &b) { return a.w > b.w; });

  vector<int> min_dist(n, INT_MAX);
  vector<vector<pair<int, int>>> prev(n);
  prev[0] = {{-1, 0}};
  min_dist[0] = 0;

  pq.push({0, 0});
  int res = 0;
  while (!pq.empty()) {
    Node curr = pq.top();
    int dist_curr = curr.w;
    int node = curr.node;
    pq.pop();

    if (dist_curr > min_dist[node])
      continue;

    for (auto [v, weight] : adj[node]) {
      int newDist = dist_curr + weight;
      if (newDist < min_dist[v]) {
        // cout << "improving from: " << node << " to " << v
        //      << " with weight: " << weight << endl;
        prev[v] = {{node, weight}};
        min_dist[v] = newDist;
        pq.push({v, newDist});
      } else if (newDist == min_dist[v]) {
        prev[v].push_back({node, weight});
      }
    }
  }
  ll sum = 0;
  backtraking(prev, n - 1, sum, visited);
  // for (int i = n - 1; i >= 0; i--) {
  //   cout << "from " << i << " can go to: ";
  //   for (auto [destination, w] : prev[i]) {
  //     cout << destination << " { " << w << "} ";
  //   }
  //   cout << endl;
  // }
  cout << sum * 2 << endl;
}
