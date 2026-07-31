#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Jump {
  ll a, b, c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; ll x; cin >> n >> x;
    //vector<Jump> v;
    ll bestFactor = LLONG_MIN;
    ll start = 0;
    for (int i = 0; i < n; i++) {
      ll a, b, c; cin >> a >> b >> c;
      if (a*b-c > bestFactor) {
        bestFactor = a*b-c;
      }

      start += a*(b-1);
    }

    if (start >= x) {
      cout << "0\n";
      continue;
    }

    if (bestFactor <= 0) {
      cout << "-1\n";
      continue;
    }

    ll target = x - start;
    //ll res = ceil(target / bestFactor);
    ll res = (target + bestFactor - 1) / bestFactor;
    cout << res << endl;


  }

  return 0;
}
