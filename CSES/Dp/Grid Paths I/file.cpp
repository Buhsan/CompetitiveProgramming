#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<vector<bool>> grid(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c; cin >> c;
      grid[i][j] = (c == '.');
    }
  }

  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = grid[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = (i == 0 && j == 0 ? dp[i][j] : (grid[i][j] ? ((i-1 < 0 ? 0 : dp[i-1][j]) + (j-1 < 0 ? 0 : dp[i][j-1])) % MOD : 0));
    }
  }
  cout << dp[n-1][n-1] << '\n';
  return 0;
}
