#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

struct Node {
  int v, weight;
};


struct Comparator {

  bool operator() (const Node& a, const Node& b) {
    return a.weight >  b.weight;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int cnt = 0;
  while (cin >> n && n) {
    cnt++;

    vector<vector<Node>> adj(n);

    for (int i = 0; i < n; i++) {
      int m; cin >> m;
      for (int j = 0; j < m; j++) {
        int u; cin >> u; u--;
        int w; cin >> w;
        adj[i].push_back({u,w});
      }
    }

    int start, end; cin >> start >> end;
    start--;
    end--;

    priority_queue<Node, vector<Node>, Comparator> pq;
    vector<int> dist(n, INT_MAX);
    pq.push({start, 0});
    dist[start] = 0;
    vector<int> prev(n, -1);
    //prev[start] = -1;


    while (!pq.empty()) {
      Node curr = pq.top();
      pq.pop();

      int u = curr.v;

      //if (curr.weight > dist[u]) continue;


      for (Node node : adj[u]) {
        int v = node.v;
        int w = node.weight;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          prev[v] = u;
          pq.push({v, dist[v]});
        }
      }
    }

    /*for (int i = 0; i < n; i++) {
      cout << prev[i] << " ";
    }
    cout << endl;*/

    
    cout << "Case " << cnt << ": Path =";
    int curr = end;
    vector<int> path;
    while (curr != -1) {
      path.push_back(curr+1);
      curr = prev[curr];
    }
    reverse(path.begin(), path.end());
    cout << " " << path[0]; 
    for (int i = 1; i < path.size(); i++) {
      cout << " " << path[i];
    }
    
    cout << "; " << dist[end] << " second delay\n";
  }



return 0;
}
