#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define TESTCASES 0

vector<pair<int, int>> dirs = {{1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, -1}, {-1, -1}};

void dfs(int i, int j, vector<vector<char>> &mapa2) {
  stack<pair<int, int>> st;
  st.push({i, j});
  mapa2[i][j] = '-'; // Mark as visited immediately

  while (!st.empty()) {
    pair<int, int> actual = st.top();
    st.pop();

    int i = actual.first;
    int j = actual.second;

    int nBombas = 0;
    for (pair<int, int> dir : dirs) {
      int newI = i + dir.first;
      int newJ = j + dir.second;

      if (newI >= 0 && newI < (int)mapa2.size() && newJ >= 0 && newJ < (int)mapa2[0].size()) {
        if (mapa2[newI][newJ] == '*') nBombas++;
      }
    }

    if (nBombas == 0) {
      mapa2[i][j] = '-';
      for (pair<int, int> dir : dirs) {
        int newI = i + dir.first;
        int newJ = j + dir.second;

        if (newI >= 0 && newI < (int)mapa2.size() && newJ >= 0 && newJ < (int)mapa2[0].size() && mapa2[newI][newJ] == 'X') {
          mapa2[newI][newJ] = '-'; // Mark as visited
          st.push({newI, newJ});
        }
      }
    } else {
      mapa2[i][j] = nBombas + '0';
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> mapa2(n, vector<char>(m, 'X'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;

      if (x == '*') {
        mapa2[i][j] = x;
      }
    }
  }

  int k;
  cin >> k;
  for (int x = 0; x < k; x++) {
    int i, j;
    cin >> i >> j;
    i--, j--;

    if (mapa2[i][j] == '*') {
      cout << "GAME OVER" << endl;
      return;
    }

    dfs(i, j, mapa2);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mapa2[i][j] == '*') cout << "X";
      else cout << mapa2[i][j];
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
