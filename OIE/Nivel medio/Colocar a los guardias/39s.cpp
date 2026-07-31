#include <bits/stdc++.h>

using namespace std;


void dfs (int u, bool colorId, int &color0, int &color1, vector<vector<int>> &adj, vector<int> &visited, bool &correct) {

  visited[u] = colorId;

  if (colorId) {
    color1++;
    //cout << "counting as color1" << endl;
  } else if (!colorId) {
    color0++;
    //cout << "counting as color0" << endl;
  }

  for (int v : adj[u]) {
    if (visited[v] == -1) {
      dfs(v, !colorId, color0, color1, adj, visited, correct);
    } else if (visited[v] == colorId) {
      correct = false;
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v; u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> visited(n,-1);
    int res = 0;
    int color1 = 0, color2 = 0;
    bool correct = true;
    for (int i = 0; i < n; i++) {
      if (visited[i] == -1) {
        //cout << "i: " << i+1 << endl;
        visited[i] = true;
        color1 = 0; color2 = 0;
        dfs(i, 0, color1, color2, adj, visited, correct);
        //cout << endl;
        //cout << "res: " << res << endl;
        res += min(color1, color2);
      }
    }
    //cout << endl;
    //cout << "colors: " <<  color1 << " " << color2 << endl;
    //cout << "total edges: " << m << " visited: " << cntEdges << " result: " << res << endl;

    if (!correct) {
      cout << "IMPOSIBLE\n";
    } else {
      cout << res << '\n';
    }
  }

  return 0;
}
