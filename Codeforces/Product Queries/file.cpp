#include <bits/stdc++.h>
using namespace std;

unordered_set<int> divisors(int n) {
  unordered_set<int> ans;

  ans.insert(1);

  for (int i = 1; i <= sqrt(n); i++) {
    if (n%i == 0) {
      if (n/i == i) ans.insert(i);
      else {
        ans.insert(n/i);
        ans.insert(i);
      }
    }
  }

  return ans;
}

int solve(int x, vector<int> &dp) {
  if (dp[x] != -1) return dp[x];
  dp[x] = INT_MAX;

  for (int div : divisors(x)) {
    int num = solve(x/div, dp);
    int num2 = solve(div, dp);
    int res = INT_MAX;
    if (num != INT_MAX && num2 != INT_MAX) {
      res = num + num2;
    }
    dp[x] = min(dp[x], res);
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
      int num = solve(i + 1, dp); 
      if (num == INT_MAX) cout << -1;
      else cout << num;
      cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
