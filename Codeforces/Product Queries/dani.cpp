#include <bits/stdc++.h>
using namespace std;

unordered_set<int> divisors(int x) {
  unordered_set<int> ans;

  ans.insert(1);

  for (int i = 2; i * i <= x; i++) {
    if (i % x == 0) {
      ans.insert(i);
      if (i != x / i) ans.insert(x / i);
    }
  }

  return ans;
}

int solve(int x, vector<int> &dp) {
  if (dp[x] != -1) return dp[x];
  dp[x] = INT_MAX;

  for (int div : divisors(x)) {
    dp[x] = min(dp[x], 1 + x / div);
  }

  return dp[x];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> dp(n + 5, -1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      dp[x] = 1;
    }

    for (int i = 0; i < n; i++) {
      cout << solve(i + 1, dp) << " ";
    }
    cout << "\n";
  }
  return 0;
}
