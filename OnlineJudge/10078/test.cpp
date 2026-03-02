#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }

template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}

  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }

  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  double dist() const { return sqrt((double)dist2()); }
  double angle() const { return atan2(y, x); }

  P unit() const { return *this/dist(); }
  P perp() const { return P(-y, x); }
  P normal() const { return perp().unit(); }
  P rotate(double a) const { 
    return P(x*cos(a)-y*sin(a), x*sin(a)+y*cos(a)); 
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

typedef Point<long long> Pll;
typedef Point<double> Pd;


struct Line { double a, b, c; };

Line normalizeLine(Line r) {
  double z = hypot(r.a, r.b);
  if (z > EPS) { r.a /= z; r.b /= z; r.c /= z; }
  if (r.a < -EPS || (abs(r.a) < EPS && r.b < -EPS)) {
    r.a = -r.a; r.b = -r.b; r.c = -r.c;
  }
  return r;
}

Line getLine(Pd p1, Pd p2) {
  double a = p1.y - p2.y, b = p2.x - p1.x;
  return normalizeLine({a, b, -a * p1.x - b * p1.y});
}

template <class P> int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

template <class P> bool onSegment(P s, P e, P p) {
  return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template <class P> double segDist(P s, P e, P p) {
  if (s == e) return (p-s).dist();
  auto d = (e-s).dist2(), t = min(d, max(decltype(d)(0), (p-s).dot(e-s)));
  return ((p-s)*d - (e-s)*t).dist() / d;
}

double distPointLineProj(Pd p, Pd a, Pd b, Pd &proj) {
  double l2 = (a - b).dist2();
  if (l2 < EPS) { proj = a; return (p - a).dist(); }
  double t = (p - a).dot(b - a) / l2;
  proj = a + (b - a) * t;
  return (p - proj).dist();
}


int lineLinePro(Line l1, Line l2, vector<Pd> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS) {
    if (abs(l1.a * l2.c - l1.c * l2.a) < EPS && abs(l1.b * l2.c - l1.c * l2.b) < EPS) return 2;
    return 0;
  }
  double x = (l1.b * l2.c - l2.b * l1.c) / det, y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back(Pd{(abs(x) < EPS ? 0 : x), (abs(y) < EPS ? 0 : y)});
  return 1;
}

Pd simetrico(const Pd &P, const Line &e) {
  vector<Pd> sol;
  lineLinePro(e, {-e.b, e.a, e.b * P.x - e.a * P.y}, sol);
  return Pd(2 * sol[0].x - P.x, 2 * sol[0].y - P.y);
}

bool circleLine(double r, Pd center, Line t, vector<Pd> &sol) {
  t = normalizeLine(t);
  Line nl = {t.a, t.b, t.a * center.x + t.b * center.y + t.c};
  double d0_sq = (nl.c * nl.c) / (nl.a * nl.a + nl.b * nl.b);
  if (d0_sq > r * r + EPS) return false;

  double x0 = (-nl.a * nl.c) / (nl.a * nl.a + nl.b * nl.b) + center.x;
  double y0 = (-nl.b * nl.c) / (nl.a * nl.a + nl.b * nl.b) + center.y;
  if (abs(d0_sq - (r * r)) < EPS) { sol.push_back(Pd{x0, y0}); return true; }

  double m = sqrt(max(0.0, r * r - d0_sq) / (nl.a * nl.a + nl.b * nl.b));
  sol.push_back(Pd{x0 + nl.b * m, y0 - nl.a * m});
  sol.push_back(Pd{x0 - nl.b * m, y0 + nl.a * m});
  return true;
}

bool circleCircle(double r1, Pd c1, double r2, Pd c2, vector<Pd> &sol) {
  Pd rel = c2 - c1; double d = rel.dist();
  if (d > r1 + r2 + EPS || d < abs(r1 - r2) - EPS || (d < EPS && abs(r1 - r2) < EPS)) return false;
  return circleLine(r1, c1, {-2 * rel.x, -2 * rel.y, rel.dist2() + r1 * r1 - r2 * r2}, sol);
}


template <class T> T polygonArea2(vector<Point<T>> v) {
  T a = v.back().cross(v[0]);
  for(size_t i = 0; i < v.size()-1; ++i) a += v[i].cross(v[i+1]);
  return a;
}

template <class P> int pointInPolyPro(P p, const vector<P> &poly) {
  int n = poly.size();
  if (n < 3) return (n == 2 && onSegment(poly[0], poly[1], p)) || (n == 1 && p == poly[0]) ? 2 : 0;
  auto o1 = poly[0].cross(poly[1], p), o2 = poly[0].cross(poly[n-1], p);
  if (o1 < 0 || o2 > 0) return 0;
  if (o1 == 0) return onSegment(poly[0], poly[1], p) ? 2 : 0;
  if (o2 == 0) return onSegment(poly[0], poly[n-1], p) ? 2 : 0;

  int l = 1, r = n - 1;
  while (r - l > 1) { 
    int m = l + (r - l) / 2;
    (poly[0].cross(poly[m], p) >= 0 ? l : r) = m;
  }
  auto ori = poly[l].cross(poly[r], p);
  return ori > 0 ? 1 : (ori == 0 && onSegment(poly[l], poly[r], p) ? 2 : 0);
}

template <class P> vector<P> convexHull(vector<P> pts, bool col = false) {
  if (pts.size() <= 1) return pts;
  sort(pts.begin(), pts.end());
  if (col) pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<P> h(pts.size() * 2);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
    for (P p : pts) {
      while (t >= s + 2 && (col ? h[t-2].cross(h[t-1], p) < 0 : h[t-2].cross(h[t-1], p) <= 0)) t--;
      h[t++] = p;
    }
  if (col && t == 2 * (int)pts.size() - 1) return pts;
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template <class P> void graham(vector<P>& pts, bool col = false) {
  sort(pts.begin(), pts.end(), [](P a, P b) { return tie(a.y, a.x) < tie(b.y, b.x); });
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  int n = pts.size(), k = 0;
  if (n <= 2) return;
  P p0 = pts[0];
  sort(pts.begin() + 1, pts.end(), [p0](P a, P b) {
    auto c = p0.cross(a, b);
    return c != 0 ? c > 0 : (a - p0).dist2() < (b - p0).dist2();
  });
  if (col) {
    int i = n - 1;
    while (i > 0 && p0.cross(pts[i], pts[i-1]) == 0) i--;
    reverse(pts.begin() + i, pts.end());
  }
  vector<P> h(n);
  for (P p : pts) {
    while (k >= 2 && (col ? h[k-2].cross(h[k-1], p) < 0 : h[k-2].cross(h[k-1], p) <= 0)) k--;
    h[k++] = p;
  }
  h.resize(k); pts = h;
}


template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0)
    return {-(s1.cross(e1, s2) == 0), P(0, 0)};
  auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}


template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) { // false: boundary true, true: boundary false
  int cnt = 0, n = p.size();
  for (int i = 0; i < n; i++) {
    P q = p[(i + 1) % n];
    if (onSegment(p[i], q, a)) return !strict;
    cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

bool isCritical(vector<Pd>& points) {
  int n = points.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      Pd a = points[i];
      Pd b = points[j];
      Pd mid = Pd{(a.x + b.x)/2.0, (a.y + b.y)/2.0};
      if (!inPolygon(points, mid, false)) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<Pd> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    cout << (isCritical(points) ? "Yes" : "No") << '\n';
  } 

  return 0;
}
