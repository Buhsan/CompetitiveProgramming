#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> freq;
    vector<vector<int>> v (n, vector<int>(n));
    for(int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
        freq[v[i][j]]++;
      }
    }

    bool res = true;
    for (auto p : freq) {
      if (p.second >= (n*n) - (n-1)) {
        res = false;
        break;
      }
    }

    cout << (res ? "YES" : "NO") << '\n';
  }

  return 0;
}
