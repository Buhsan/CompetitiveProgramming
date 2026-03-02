#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1, 0}, {1,1}, {-1,-1}, {1, -1}, {-1,1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int t = 1;
  while (cin >> n >> m && (n || m)) {
    if (t > 1) cout << '\n';
    vector<string> grid;
    vector<pair<int,int>> bombs;
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      grid.push_back(s);
      for (int j = 0; j < m; j++) {
        if (s[j] == '*') {
          bombs.push_back({i,j});
        }
      }
    }
    
    vector<vector<char>> res (n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '*') {
          res[i][j] = '*';
          continue;
        }
        int cnt = 0;
        for (pair<int, int> d : dirs) {
          int ni = i + d.first;
          int nj = j + d.second;
          if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '*') {
            cnt++;
          }
        }
        res[i][j] = cnt+'0';
      }
    }

    cout << "Field #" << t << ":\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << res[i][j];
      }
      cout << '\n';
    }
    t++;
  }
  return 0;
}
