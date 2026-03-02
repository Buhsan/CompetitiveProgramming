#include <bits/stdc++.h>

using namespace std;

vector<int> dp, visited;
bool infini;

int dfs (int i, const string &s) {
  if (i < 0 || i >= s.size()) return 0;
  if (visited[i] == 1) {
    infini = true;
    return 0;
  }
  if (visited[i] == 2)  return dp[i];

  visited[i] = 1;

  int best = 0;

  if (s[i] == '<') {
    best = 1 + dfs(i-1, s);
  } else if (s[i] == '>') {
    best = 1 + dfs(i+1, s);
  } else {
    best = 1 + max(dfs(i-1,s), dfs(i+1,s));
  }

  visited[i] = 2;
  dp[i] = best;
  return best;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {

    string s;
    cin >> s;
    int n = s.size();



    int ans = 0;

    dp = vector<int>(n,0);
    visited = vector<int>(n,0);
    infini = false;

    for (int i = 0; i < n; i++) {
      ans = max(ans, dfs(i,s));
    }
    if (infini) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
  
  return 0;
}
