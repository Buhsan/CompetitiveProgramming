#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, maxPrice; cin >> n >> maxPrice;

  vector<int> prices(n);
  for (int i = 0; i < n; i++) cin >> prices[i];

  vector<int> pages(n);
  for (int i = 0; i < n; i++) cin >> pages[i];

  vector<vector<int>> dp(n + 1, vector<int>(maxPrice + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= maxPrice; j++) {
      int coger = 0;
      if (j >= prices[i - 1]) {
        coger = pages[i - 1] + dp[i - 1][j - prices[i - 1]];
      }
      int noCoger = dp[i - 1][j];
      dp[i][j] = max(coger, noCoger);
    }
  }
  cout << dp[n][maxPrice] << "\n";

  return 0;
}
