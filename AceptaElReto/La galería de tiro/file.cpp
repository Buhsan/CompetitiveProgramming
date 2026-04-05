#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N = 500002;

  int dp[N];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 2;

  for (int i = 5; i < N; i++) {
    if (i % 2 == 0) {
      dp[i] = dp[i/2+1] + dp[i/2] - 1;
    } else  {
      dp[i] = dp[i/2+1] + dp[i/2+1] - 1;
    }
  }


  int n;
  while (cin >> n && n) {
    int res = 0;
    if (n > 500000) {
      if (n % 2 == 0) {
        res = dp[n/2+1] + dp[n/2] - 1;
      } else  {
        res = dp[n/2+1] + dp[n/2+1] - 1;
      }
      cout << res << '\n';
    } else {
      cout << dp[n] << '\n';
    }
  }
  

  return 0;
}
