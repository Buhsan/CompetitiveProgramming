#include <bits/stdc++.h>

using namespace std;

int solve (int low, int high, vector<vector<int>> &dp, vector<int> &v) {
  int n = v.size();
  if (low > high) return 0;
  if (dp[low][high] != -1) return dp[low][high];



  int cost = solve(low + 1, high, dp,v) + 1;
  for (int i = low+1; i <= high; i++) {
    if (v[low] == v[i]) {
      cost = min(cost, solve(low+1, i-1, dp, v) + solve(i+1, high, dp, v));
    }
  }

  return dp[low][high] = cost;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<vector<int>> dp (n, vector<int>(n,-1));

  cout << solve(0, n-1, dp, v) << '\n';
  
  

  return 0;
}
