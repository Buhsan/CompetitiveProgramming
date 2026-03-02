#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, v;
    cin >> n >> v;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ans = 0;
    int start = 0;
    int end = n - 1;

    while (start < end) {
      if (p[start] + p[end] >= v) {
        ans++;
        start++;
        end--;
      } else {
        start++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
