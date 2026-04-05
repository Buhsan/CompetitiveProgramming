#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 999999999989;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    ll dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = 0;
      for (int j = 1; j <= k; j++) {
        if (i-j < 0) continue;
        dp[i] = ((dp[i] + dp[i-j]) % MOD + (i==j)) % MOD;
      }
    }
    cout << dp[n] % MOD  << '\n';
  }
}

