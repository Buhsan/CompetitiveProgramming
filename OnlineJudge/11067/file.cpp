#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  while (cin >> n >> m) {
    if (!m && !n) break;
    int t; cin >> t;
    vector<vector<bool>> wolfs(n + 1, vector<bool>(m+1, false));
    for (int i = 0; i < t; i++) {
      int a, b; cin >> a >> b;
      wolfs[a][b] = true;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m+1));
    dp[0][0] = !wolfs[0][0];

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if(wolfs[i][j]) continue;
        if (i-1 >= 0) dp[i][j] += dp[i-1][j];
        if (j-1 >= 0 ) dp[i][j] += dp[i][j-1];
      }
    }
    ll ans = dp[n][m];
    if (ans == 0) {
      cout << "There is no path.\n";
    } else if (ans == 1) {
      cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
    } else {
      cout << "There are " << ans << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
    }
  }
  return 0;
}
