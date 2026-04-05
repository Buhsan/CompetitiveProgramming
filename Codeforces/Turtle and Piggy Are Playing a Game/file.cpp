#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int l, r; cin >> l >> r;
    int res = (int)log2(r);
    cout << res << '\n';
  }

  return 0;
}
