#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0},   {0, -1}, {-1, 0},
                               {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
vector<string> grid;
vector<pair<int, int>> bombs;
vector<vector<int>> bombGrid;
int n, m;

struct Node {
  int i, j;
};

void open(int a, int b) {
  if (a < 0 || a >= n || b < 0 || b >= m || grid[a][b] != 'X') return;

  if (bombGrid[a][b] > 0) {
    grid[a][b] = bombGrid[a][b] + '0';
    return;
  } else if (bombGrid[a][b] == 0) {
    grid[a][b] = '-';
    for (pair<int, int> dir : dirs) {
      open(a + dir.first, b + dir.second);
    }
  }
}

void calcBombs() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      if (bombGrid[i][j] == -1) continue;
      for (pair<int, int> dir : dirs) {
        int newI = i + dir.first;
        int newJ = j + dir.second;
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < m) {
          cnt += (bombGrid[newI][newJ] == -1);
        }
      }
      bombGrid[i][j] = cnt;
    }
  }
} int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n >> m) {
    grid.clear();
    bombs.clear();
    bombGrid = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      string aux = "";
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        aux += 'X';
        if (c == '*')
          bombs.push_back({i, j}), bombGrid[i][j] = -1;
      }
      grid.push_back(aux);
    }

    calcBombs();
    int q;
    cin >> q;
    bool result = true;
    while (q--) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (result) {
        if (bombGrid[a][b] == -1) {
          result = false;
        } else {
          open(a,b);
        }
      }
    }


    if (result) {
      for (int i = 0; i < n; i++) {
        cout << grid[i] << '\n';
      }
    } else {
      cout << "GAME OVER\n";
    }

  }
  return 0;
}
