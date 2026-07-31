#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int dest, vector<vector<int>> &adj, vector<int> &visited, bool &cycle, bool &finish) {
  //cout << "u: " << u << endl;
  visited[u] = 1;
  if (u == dest) {
    finish = true;
    return;
  }

  for (int v : adj[u]) {
    if (visited[v] == 1) {
      cycle = true;
    }
    if (visited[v] == 0) {
      dfs(v, dest, adj, visited, cycle, finish);
    }
  }
  visited[u] = 2;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
      char c; cin >> c;
      if (c == 'A') {
        adj[i].push_back(i+1);
      } else if (c == 'J') {
        int nd; cin >> nd;
        nd--;
        adj[i].push_back(nd);
      } else if (c == 'C') {
        int nd; cin >> nd;
        nd--;
        adj[i].push_back(nd);
        adj[i].push_back(i+1);
      }
    }
    vector<int> visited(n+1);
    bool cycle = false;
    bool finish = false;

    dfs(0, n, adj, visited, cycle, finish);

    if (!finish) {
      cout << "NUNCA\n";
      continue;
    }
    if (cycle) {
      cout << "A VECES\n";
    } else {
      cout << "SIEMPRE\n";
    }
  }
  return 0;
}

