#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<ll> pref(n);
    pref[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
      pref[i] = pref[i+1] + v[i];
    }
    ll res = 0;

    for (int i = 0; i < n-1; i++) {
      res += (v[i] * pref[i+1]);
    }
    cout << res << '\n';
  }

  return 0;
}
