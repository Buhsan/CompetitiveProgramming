#include <bist/stdc++.h>

using namespace std;


struct Node {
  int nd, weight;
}

struct NodeComparator {
  bool operator() (const Node& a, const Node& b) {
    return a.weight > b.weight;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<pair<int,int>>> adj(n);
    for (int i = 0; i < n; i++) {
      int u, v, d; cin >> u >> v >> d;
      u--, v--;
      adj[u].push_back({v,d});
      adj[v].push_back({u,d});
    }

    vector<int> dist(n, INT_MAX);
    int ini = 0;
    int fin = n-1;
    priority_queue<Node, vector<Node>, NodeComparator> pq;

    dist[ini] = 0;

    pq.push({ini,0});

    while(!pq.empty()) {
      Node curr = pq.top();
      pq.pop();

      int u = curr.nd;
      int uWeight = curr.weight;

      if (uWeight > dist[u]) continue;

      for (pair<int,int> &p : adj[u]) {
        int v = p.first;
        int w = p.second;

        int newWeight = uWeight + w;
        if (dist[v] > newWeight) {
          dist[v] = newWeight;


        }

      }

    }

  }


  return 0;
}
