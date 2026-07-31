#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    ll x, y; cin >> x >> y;
    if (abs(x-y) > x) cout << "YES\n";
    else cout << "NO\n";
  }


  return 0;
}
