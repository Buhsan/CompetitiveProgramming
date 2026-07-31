#include <bits/stdc++.h>

using namespace std;


const int MOD = 1e9 + 7;


int solve(int i, vector<int> &dp, vector<vector<int>> &adj) {
  if (dp[i] != -1) return dp[i];
  //dp[i] += 1;
  dp[i] = 0;

  for (int prev : adj[i]) {
    dp[i] = (dp[i] + solve(prev, dp, adj)) % MOD;
  }

  return dp[i];
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  
  while (cin >> n) {
    vector<vector<int>> adj(n);
    vector<int> finales(n); // 0 - nada, 1 - feliz, 2 - amargo
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      if (a == 0) {
        string f; cin >> f;
        if (f == "FELIZ") finales[i] = 1;
        else if (f == "AMARGO") finales[i] = 2;
      }
      for (int j = 0; j < a; j++) {
        int b; cin >> b; b--;
        adj[b].push_back(i);
      }
    }

    vector<int> dp(n, -1); // dp[seq_i] = num de maneras de llegar a seq_i desde seq_0
    dp[0] = 1;

    int good = 0;
    int bad = 0;

    for (int i = 0; i < n; i++) {
      if (finales[i] == 1) {
        good = (good + solve(i, dp, adj)) % MOD;
      } else if (finales[i] == 2) {
        bad = (bad + solve(i, dp, adj)) % MOD;
      }
    }


    cout << good << " " << bad << '\n';


  }

  return 0;
}
