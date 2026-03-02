#include <bits/stdc++.h>

using namespace std;

bool willFall(int i, const string &s, vector<int> &dp) {
  int n = dp.size();
  if (i == -1 || i == n) return true;
  if (dp[i] != -1) return dp[i];

  dp[i] = false;
  if (s[i] == '>') {
    return dp[i] |= willFall(i + 1, s, dp);
  }
  return dp[i] |= willFall(i - 1, s, dp);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> dp(n, -1);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += willFall(i, s, dp);
  }

  cout << ans << "\n";


  return 0;
}
