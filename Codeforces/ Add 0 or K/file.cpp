#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll euclid (ll a, ll b, ll &x, ll &y) {
  if (!b) return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a/b * x, d;
}


ll solve (ll a, ll b, ll m) {
  //cout << "old: a = " << a << " b = " << b << " m = " << m << endl;
  a = (a%m + m) % m;
  b = (b%m + m) % m;
  //cout << "new: a = " << a << " b = " << b << " m = " << m << endl;
  ll x, y;
  euclid(a, m, x, y);
  //cout << "x: " << x << endl;
  ll res = x * b;
  return (res % m + m) % m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    bool even = (k % 2 == 0);
    for (int i = 0; i < n; i++) {
      ll res = 0;
      ll a; cin >> a;
      if (even) {
        ll mult = solve(k, -a, k+1);
        //cout << "mult: " << mult << endl;
        res = a + (k*mult);
      } else {
        if (a%2==0) res = a;
        else res = a + k;
      }
      cout << res << " ";
    }
    cout << endl;
  }

  return 0;
}
