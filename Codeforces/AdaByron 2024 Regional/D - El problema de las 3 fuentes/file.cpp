#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;

  Point() { }
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
};

double dist(Point &A, Point &B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void solve() {
  Point A, B, C;

  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

  // Recta intersección A, B
  double m1 = -(B.x - A.x) / (B.y - A.y);
  double n1 = -m1 * ((A.x + B.x) / 2.0) + ((A.y + B.y) / 2.0);

  bool firstSpecial = false;
  double x1 = 0;
  if (fabs(B.y - A.y) < 1e-9) {
    firstSpecial = true;
    x1 = (A.x + B.x) / 2.0;
  }

  // Recta intersección A, C
  double m2 = -(C.x - A.x) / (C.y - A.y);
  double n2 = -m2 * ((A.x + C.x) / 2.0) + ((A.y + C.y) / 2.0);

  bool secondSpecial = false;
  double x2 = 0;
  if (fabs(C.y - A.y) < 1e-9) {
    secondSpecial = true;
    x2 = (A.x + C.x) / 2.0;
  }

  // Recta intersección B, C
  double m3 = -(C.x - B.x) / (C.y - B.y);
  double n3 = -m3 * ((B.x + C.x) / 2.0) + ((B.y + C.y) / 2.0);

  bool thirdSpecial = false;
  double x3 = 0;
  if (fabs(C.y - B.y) < 1e-9) {
    thirdSpecial = true;
    x3 = (B.x + C.x) / 2.0;
  }

  // cout << m1 << " " << n1 << endl;
  Point X((n2 - n1) / (m1 - m2), (n2 - n1) / (m1 - m2) * m1 + n1);

  if (firstSpecial) {
    X.x = x1;
    X.y = m2 * x1 + n2;
  } else if (secondSpecial) {
    X.x = x2;
    X.y = m1 * x2 + n1;
  }
  // cout << X.x << " " << X.y << endl;
  
  Point esq1(0, 0);
  Point esq2(100, 0);
  Point esq3(0, 100);
  Point esq4(100, 100);

  vector<Point> posibles = {esq1, esq2, esq3, esq4, X};

  double ans = 0;

  // X = 0
  if (!firstSpecial) posibles.push_back({0, m1 * 0 + n1});
  if (!secondSpecial) posibles.push_back({0, m2 * 0 + n2});
  if (!thirdSpecial) posibles.push_back({0, m3 * 0 + n3});
  // X = 100
  if (!firstSpecial) posibles.push_back({100, m1 * 100 + n1});
  if (!secondSpecial) posibles.push_back({100, m2 * 100 + n2});
  if (!thirdSpecial) posibles.push_back({100, m3 * 100 + n3});
  // Y = 0
  if (firstSpecial) {
    posibles.push_back({x1, 0});
  } else {
    posibles.push_back({-n1 / m1, 0});
  }
  if (secondSpecial) {
    posibles.push_back({x2, 0});
  } else {
    posibles.push_back({-n2 / m2, 0});
  }
  if (thirdSpecial) {
    posibles.push_back({x3, 0});
  } else {
    posibles.push_back({-n3 / m3, 0});
  }
  // Y = 100
  if (firstSpecial) {
    posibles.push_back({x1, 100});
  } else {
    posibles.push_back({(100 - n1) / m1, 100});
  }
  if (secondSpecial) {
    posibles.push_back({x2, 100});
  } else {
    posibles.push_back({(100 - n2) / m2, 100});
  }
  if (thirdSpecial) {
    posibles.push_back({x3, 100});
  } else {
    posibles.push_back({(100 - n3) / m3, 100});
  }

  for (Point &P : posibles) {
    if (P.x > 100 || P.y > 100 || P.x < 0 || P.y < 0) continue;
    ans = max(ans, min({dist(P, A), dist(P, B), dist(P, C)}));
  }

  cout << fixed << setprecision(3) << ans << endl;
}

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    solve();
  }
}

