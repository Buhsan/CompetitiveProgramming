#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

template<class T>
struct Point {
  typedef Point P;
  T x, y;
  Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y);}
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / sqrt((double)(x*x + y*y)); }
  P perp() const { return P(-y, x); }
  P normal() const { return perp().unit(); }
  P rotate(double a) const { return P(x*cos(a)-y*sin(a), x*sin(
    a)+y*cos(a)); }
  friend ostream& operator<<(ostream& os, P p) { return os << "(" << p.x << "," << p.y << ")"; }
};

struct Line {
  double a, b, c;
  friend ostream& operator<<(ostream& os, Line l) { return os
    << l.a << "x + " << l.b << "y + " << l.c << " = 0"; }
};
Line normalizeLine(Line r) {
  double z = hypot(r.a, r.b);
  if (z > EPS) r.a /= z, r.b /= z, r.c /= z;
  if (r.a < -EPS || (abs(r.a) < EPS && r.b < -EPS)) r.a = -r.a,
    r.b = -r.b, r.c = -r.c;
  return r;
}
template <class P>
Line getLine(P p1, P p2) {
  double a = p1.y - p2.y, b = p2.x - p1.x;
  return normalizeLine({a, b, -a * p1.x - b * p1.y});
}
template <class P>
int lineLinePro(Line l1, Line l2, vector<P> &sol) { 
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS)
    return (abs(l1.a * l2.c - l1.c * l2.a) < EPS && abs(l1.b *
                                                        l2.c - l1.c * l2.b) < EPS) ? 2 : 0;
  return sol.push_back({(l1.b * l2.c - l2.b * l1.c) / det, (l1.
    c * l2.a - l2.c * l1.a) / det}), 1;
}

typedef long long ll;
typedef Point<ll> Pll;
typedef Point<double> Pd;

int relPosLine(Pll p, Line t) {
  double dist = t.a*p.x + t.b*p.y + t.c;
  if (dist > 0) return 1;
  if (dist < 0) return -1;
  return 0;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n; cin >> n;
    vector<Line> lines;
    for (int i = 0; i < n; i++) {
      ll x, y, x1, y1; cin >> x >> y >> x1 >> y1;
      lines.push_back(getLine(Pll{x,y}, Pll{x1,y1}));
    }
    for (int i = 0; i <= 1000; i++) {
      for (int j = 0; j <= 1000; j++) {
        for (int k = 0; k < n; k++) {

        }
      }
    }

  }


  return 0;
}
