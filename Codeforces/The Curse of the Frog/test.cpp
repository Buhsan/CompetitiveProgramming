#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Jump {
  int a, b, c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; ll x; cin >> n >> x;
    vector<Jump> v;
    int bestId = -1;
    int bestFactor = 0;
    for (int i = 0; i < n; i++) {
      int a, b, c; cin >> a >> b >> c;
      if (a*b-c > bestFactor) {
        bestFactor = a*b-c;
        bestId = i;
      }

      v.push_back({a, b, c});
    }
    if (bestId == -1) {
      cout << "-1\n";
      continue;
    }
    ll res = 0;
    if (n == 1) {
      ll f = v[0].a * v[0].b - v[0].c;
      res = ceil((double)x/f*1.0);

      if (v[0].b > 1) {
        cout << "curr res: " << res << endl;
        res = min(res, (ll)ceil((double)(x-v[0].a)/f*1.0));
        cout << "new res: " << res << endl;
      }

    } else {
      int start = 0;
      for (int i = 0; i < n; i++) {
        if (i == bestId) continue;
        if (v[i].b == 1) continue;
        start+=v[i].a*(v[i].b-1);
      }

      if (start >= x) {
        cout << 0 << '\n';
        continue;
      }

      ll target = x - start;
      ll f = (ll)(v[bestId].a * v[bestId].b) - v[bestId].c;
      res = ceil((double)target/f*1.0);
    }

    cout << res << '\n';


  }

  return 0;
}
