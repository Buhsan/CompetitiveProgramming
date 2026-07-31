#include <bits/stdc++.h>

using namespace std;


void dfs(int u, vector<vector<int>> &adj, vector<int> &visited, bool &cycle) {
  cout << "u: " << u+1 << endl;
  visited[u] = 1;

  for (int v : adj[u]) {
    if (visited[v] == 1) {
      cycle = true;
    } else if (!visited[v]) {
      dfs(v, adj, visited, cycle);
    }
  }
  visited[u] = 2;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n >> m) {
    vector<vector<int>> adj(n);
    vector<vector<int>> adjT(n);

    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v; u--, v--;
      cout << "u: " << u << " v: " << v << endl;
      adj[u].push_back(v);
      adjT[v].push_back(u);
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
      vector<int> visited(n,0), visitedT(n,0);
      bool cycle = false;
      int a, b; cin >> a >> b; a--, b--;

    }


  }




  return 0;
}
