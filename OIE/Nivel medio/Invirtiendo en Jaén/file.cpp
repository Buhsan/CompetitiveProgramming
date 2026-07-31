#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}};

struct Node {
  int i, j, steps;
};

int bfs (int a, int b, vector<vector<bool>> &visited) {
  int n = visited.size();
  int m = visited[0].size();
  int ans = 0;
  queue<Node> q;
  q.push({a,b});
  int res = 0;
  while (!q.empty()) {
    Node curr = q.front();
    int i = curr.i;
    int j = curr.j;
    q.pop();
    res = max(res, curr.steps);
    for (pair<int,int> d : dirs) {
      int newi = i + d.first;
      int newj = j + d.second;
      if (newi >= 0 && newi < n && newj >= 0 && newj < m && !visited[newi][newj]) {
        visited[newi][newj] = true;
        q.push({newi, newj, curr.steps+1});
      }
    }
  }

  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c; cin >> c;
        if (c == '-') visited[i][j] = true;
      }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j]) cout << '-';
        else cout << '#';
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
          res = max(res, bfs(i, j, visited));
        }
      }
    }

    cout << res << '\n';

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j]) cout << '-';
        else cout << '#';
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
