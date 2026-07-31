#include <bits/stdc++.h>

using namespace std;


void dfs(int u, int dest, vector<vector<int>> &adj, vector<bool> &visited, bool &finish) {
  visited[u] = 1;
  if (u == dest) {
    finish = true;
  }

  for (int v : adj[u]) {
     if (!visited[v]) {
      dfs(v, dest, adj, visited, finish);
    }
  }
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
      adj[u].push_back(v);
      adjT[v].push_back(u);
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
      vector<bool> visited(n,0), visitedT(n,0);
      bool finish = false;
      bool finishT = false;
      int a, b; cin >> a >> b; a--, b--;
      dfs(a, b, adj, visited, finish);
      dfs(b, a, adjT, visitedT, finishT);
      if (!finish || !finishT) {
        cout << "IMPOSIBLE\n";
        continue;
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        if (visited[i] && visitedT[i]) res++;
      }
      cout << res-2 << '\n';
    }
    cout << "---\n";
  }

  return 0;
}
