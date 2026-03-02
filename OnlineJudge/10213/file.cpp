#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll fastPow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    ll n; cin >> n;
    cout << "n: " << n << endl;
    if (n == 0) cout << 0 << '\n';
    else {
      cout << fastPow(2, n-1) << '\n';
    }
  }

  return 0;
}
