#include <bits/stdc++.h>

using namespace std;

struct Node {
  int id, grade;
};


struct NodeSort {
  bool operator() (Node a, Node b) {
    return a.grade > b.grade;
  }

};


void dfs (int u, int color, vector<vector<int>> &adj, vector<bool> &visited, int &cntEdges, int &res) {
  for (int v : adj[u]) {
    if (!visited[v]) {
      visited[v] = true;
      cntEdges++;
      if (color == 0) res++;
      dfs(v, !color, adj, visited, cntEdges, res);
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> adj(n);
    unordered_map<int,int> grades;
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v; u--, v--;
      grades[u]++;
      grades[v]++;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<Node> v;
    for (pair<int,int> d : grades) {
      v.push_back({d.first, d.second});
    }
    sort(v.begin(), v.end(), NodeSort());

    vector<bool> visited(n);
    int num = 0;
    int res = 0;
    int cntEdges = 0;
    for (Node nd : v) {
      int i = nd.id;
      if (!visited[i]) {
        cout << "i: " << i << " grado: " << nd.grade << endl;
        visited[i] = true;
        dfs(i, 0, adj, visited, cntEdges, res);
        cout << "res: " << res << endl;
      }
    }
    //cout << "total edges: " << m << " visited: " << cntEdges << " result: " << res << endl;

    if (cntEdges == m) {
      cout << res << '\n';
    } else {
      cout << "IMPOSIBLE\n";
    }
  }

  return 0;
}
