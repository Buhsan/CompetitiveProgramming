#include <bits/stdc++.h>

using namespace std;

int main () {
  int t; cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool res = true;
    int firstMax = max(a,b);
    int firstMin = min(a,b);
    int secondMax = max(c-a,d-b);
    int secondMin = min(c-a,d-b);
    if (firstMin == 0) {
      res = firstMax < 3;
    }
    else {
      res = ceil(firstMax/(firstMin+1.0)) < 3;
    }

    if (res) {
      if (secondMin == 0) {
        res = secondMax < 3;
      }
      else {
        res = ceil(secondMax/(secondMin+1.0)) < 3;
      }
    }

    cout << (res ? "YES" : "NO") << '\n';
  }
}
