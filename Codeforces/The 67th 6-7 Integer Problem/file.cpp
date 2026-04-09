#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n = 7;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    int res = v[n-1];
    for (int i = 0; i < n-1; i++) {
      res -= v[i];
    }

    cout << res << '\n';
  }
  return 0;
}
