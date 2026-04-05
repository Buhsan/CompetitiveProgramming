#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));


  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    ll u, v, d;
    cin >> u >> v >> d;
    u--, v--;

    dp[u][v] = min(dp[u][v], d);
    dp[v][u] = min(dp[v][u], d);
  }


  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][k] != LLONG_MAX && dp[k][j] != LLONG_MAX) {
          dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
  }


  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (dp[u][v] == LLONG_MAX) {
      cout << -1 << '\n';
    } else {
      cout << dp[u][v] << '\n';
    }
  }
  
  return 0;
}
