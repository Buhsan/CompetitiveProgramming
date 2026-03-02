#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    ll maxi = -1;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
      ll a; cin >> a; v.push_back(a);
      maxi = max(maxi, a);
    }
    vector<ll> pref(n);
    pref[0] = maxi - v[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i-1] + (maxi - v[i]);
    }
    ll m; cin >> m;
    for (ll i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      a = min (a,b);
      b = max(a,b);
      a--, b--;
      cout << pref[b] - (a-1 < 0  ? 0 : pref[a-1]) << '\n';
    }
    cout << "---" << '\n';
  }
  return 0;
}
