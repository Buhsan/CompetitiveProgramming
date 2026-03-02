#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while(cin >> n && n) {
    long double maxY = DBL_MIN, maxX = DBL_MIN, minY = DBL_MAX, minX = DBL_MAX;
    for (int i = 0; i < n; i++) {
      long double x, y; cin >> x >> y;
      if (y < minY - EPS) minY = y;
      if (x < minX - EPS) minX = x;
      if (x > maxX + EPS) maxX = x;
      if (y > maxY + EPS) maxY = y;
    }
    long double dist1 = abs(maxX - minX);
    long double dist2 = abs(maxY - minY);
    cout << fixed << setprecision(4) << (long double) dist1 * dist2 << '\n';
  }

  return 0;
}
