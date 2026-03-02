#include <bits/stdc++.h>
using namespace std;

unordered_set<int> digits(int x) {
  unordered_set<int> digits;
  
  while (x > 0) {
    digits.insert(x % 10);
    x /= 10;
  }
  digits.erase(0);
  return digits;
}

int main() {
  int n;
  cin >> n;

  vector<int> dp(n + 1, INT_MAX);

  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j : digits(i)) {
      dp[i] = min(dp[i], dp[i - j] + 1);
    }
  }

  cout << dp[n] << "\n";
  return 0;
}
