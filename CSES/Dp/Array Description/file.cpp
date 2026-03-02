#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

  for (int i = 1; i <= m; i++) dp[0][i] = 1;

  for (int i = 1; i <= n; i++) {
    if (a[i - 1]) {
      dp[i][a[i - 1]] = (dp[i - 1][a[i - 1]]);
      if (i > 1) {
        if (a[i - 1] + 1 <= m) dp[i][a[i - 1]] = (dp[i][a[i - 1]] + (dp[i - 1][a[i - 1] + 1])) % MOD;
        if (a[i - 1] - 1 > 0) dp[i][a[i - 1]] = (dp[i][a[i - 1]] + (dp[i - 1][a[i - 1] - 1])) % MOD;
      }
    } else {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];
        if (i > 1) {

          if (j + 1 <= m) dp[i][j] = (dp[i][j] + (dp[i - 1][j + 1])) % MOD;
          if (j - 1 > 0) dp[i][j] = (dp[i][j] + (dp[i - 1][j - 1])) % MOD;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + dp[n][i]) % MOD;
  }
  cout << ans << "\n";

  return 0;
}
