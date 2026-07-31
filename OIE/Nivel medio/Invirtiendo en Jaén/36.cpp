#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0, -1}};

int dfs (int i, int j, vector<vector<bool>> &visited, vector<string> &mapi) {
  visited[i][j] = true;
  int n = visited.size();
  int m = visited[0].size();
  int ans = 1;
  for (pair<int,int> d : dirs) {
    int newI = i + d.first;
    int newJ = j + d.second;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && !visited[newI][newJ] && mapi[newI][newJ] != '-') {
      ans += dfs(newI, newJ, visited, mapi);
    }
  }

  return ans;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<string> mapi;
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      mapi.push_back(s);
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && mapi[i][j] != '-') {
          res = max(res, dfs(i, j, visited, mapi));
        }
      }
    }

    cout << res << '\n';
  }

  return 0;
}
