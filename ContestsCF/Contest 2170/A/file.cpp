#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0},{1, 0}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int dbl= n*n;
    vector<vector<int>> grid(n, vector<int>(n));
    int ans = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int sum = (j + i*n) + 1;
        for (auto  p : dirs) {
          int newI = i + p.first;
          int newJ = j + p.second;
          if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
            sum += (newJ + newI*n) + 1;
          }
        }
        ans = max(ans, sum);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
