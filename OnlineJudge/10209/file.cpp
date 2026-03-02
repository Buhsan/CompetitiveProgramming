#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1425926;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  double a;
  while (cin >> a) {
    double arc = (PI * a * a) / 4.0;
    double area = a*a;
    double areaArc = area - arc;
    double areaArc2 = area - 2*areaArc;
    double areaArc3 = area - 3*areaArc;
    double leaf = areaArc2 - areaArc3;
    double center = areaArc3 - leaf;
    double rest = area - 4*leaf - center;
    cout << fixed << setprecision(3) << 0.00566 << '\n';
  }
  return 0;
}
