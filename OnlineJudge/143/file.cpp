#include <bits/stdc++.h>

using namespace std;


const double EPS = 1e-9;

struct Line {
  double a,b,c;

  string toString() {
    stringstream out;
    out << "a: " << a << " b: " << b << " c: " << c;
    return out.str();
  }
};

struct Point {
  double x, y;

  bool operator < (const Point& t) const {
    if (abs(x - t.x) > EPS) return x < t.x;
    return y < t.y - EPS;
  }

  bool operator == (const Point& t) const {
    return abs(x - t.x) < EPS && abs(y - t.y) < EPS;
  }

  Point operator + (const Point& t) const { return {x + t.x, y + t.y}; }
  Point operator - (const Point& t) const { return {x - t.x, y - t.y}; }
  Point operator * (double t) const { return {x * t, y * t}; }
  Point operator / (double t) const { return {x / t, y / t}; }

  string toString() {
    stringstream out;
    out << "x: " << x << " y: " << y;
    return out.str();
  }
};

//PRIMITIVES

// Cross Product of two vectors (Origin -> a, Origin -> b)
// Returns the signed area of the parallelogram
double cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

// Cross Product of vectors (b-a) and (c-a)
// Returns value proportional to signed area of triangle abc
double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 0: Collinear
// 1: Counter-Clockwise (Left Turn)
// -1: Clockwise (Right Turn)
int orientation(Point a, Point b, Point c) {
    double v = cross(a, b, c);
    if (abs(v) < EPS) return 0;
    return (v > 0) ? 1 : -1;
}


bool cw(Point a, Point b, Point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool ccw(Point a, Point b, Point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

bool collinear(Point a, Point b, Point c) {return orientation(a, b, c) == 0;}

double dist(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}


// SEGMENT & LINES UTILS
Line normalizeLine(Line r) {
  double z = hypot(r.a, r.b);
  if (z > EPS) { r.a /= z; r.b /= z; r.c /= z; }
  if (r.a < -EPS || (abs(r.a) < EPS && r.b < -EPS)) {
    r.a = -r.a; r.b = -r.b; r.c = -r.c;
  }
  return r;
}

// Ax + By + C = 0;
Line getLine(Point p1, Point p2) {
  double a = p1.y - p2.y;
  double b = p2.x - p1.x;
  double c = -a * p1.x - b * p1.y;
  return normalizeLine({a, b, c});
}

bool onSegment(Point p, Point a, Point b) {
  if (orientation(a, b, p) != 0) return false;
  return p.x >= min(a.x, b.x) - EPS && p.x <= max(a.x, b.x) + EPS &&
  p.y >= min(a.y, b.y) - EPS && p.y <= max(a.y, b.y) + EPS;
}

// Distance from Point P to Line AB (infinite line)
// Also returns the projection point
double distPointLineProj(Point p, Point a, Point b, Point &proj) {
  double l2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (l2 < EPS) { proj = a; return dist(p, a); } // a == b case
  double t = dot(p - a, b - a) / l2;
  proj = a + (b - a) * t;
  return dist(p, proj);
}

double distPointLine(Point p, Point a, Point b) {
  Point c;
  return distPointLineProj(p, a, b, c);
}

// Distance from Point P to Segment AB
double distPointSegment(Point p, Point a, Point b) {
  double l2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (l2 < EPS) return dist(p, a);
  double t = dot(p - a, b - a) / l2;
  // Clamp t to segment range [0, 1]
  t = max(0.0, min(1.0, t));
  Point c = a + (b - a) * t;
  return dist(p, c);
}


// INTERSECTIONS
bool lineLine(Line l1, Line l2, vector<Point> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS) return false; // Parallel
  double x = (l1.b * l2.c - l2.b * l1.c) / det;
  double y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back({x, y});
  return true;
}

// Returns:
// 0: Parallel (No intersection)
// 1: Unique Intersection (sol has 1 point)
// 2: Same Line (Infinite intersections)
int lineLinePro(Line l1, Line l2, vector<Point> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS) {
    if (abs(l1.a * l2.c - l1.c * l2.a) < EPS && 
      abs(l1.b * l2.c - l1.c * l2.b) < EPS) {
      return 2; // Identical Lines (Infinite solutions)
    }
    return 0; //Parallel (No solution)
  }
  double x = (l1.b * l2.c - l2.b * l1.c) / det;
  double y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back({x, y});
  return 1;
}

bool segmentSegment(Point a, Point b, Point c, Point d, vector<Point> &sol) {
  int o1 = orientation(a, b, c);
  int o2 = orientation(a, b, d);
  int o3 = orientation(c, d, a);
  int o4 = orientation(c, d, b);

  if (o1 != o2 && o3 != o4) {
    Line l1 = getLine(a, b);
    Line l2 = getLine(c, d);
    return lineLine(l1, l2, sol);
  }

  //Collinear overlap
  if (o1 == 0 && onSegment(c, a, b)) { sol.push_back(c); return true; }
  if (o2 == 0 && onSegment(d, a, b)) { sol.push_back(d); return true; }
  if (o3 == 0 && onSegment(a, c, d)) { sol.push_back(a); return true; }
  if (o4 == 0 && onSegment(b, c, d)) { sol.push_back(b); return true; }

  return false;
}

bool circleLine(double r, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  double a = t.a;
  double b = t.b;
  double c = t.c;
  double x0 = (-a * c) / (a * a + b * b);
  double y0 = (-b * c) / (a * a + b * b);
  double d0_sq = (c * c) / ((a * a) + (b * b));

  if (d0_sq > r * r + EPS) {
    return false;
  } else if (abs(d0_sq - (r * r)) < EPS){
    sol.push_back({x0, y0});
    return true;
  } else {
    double dt = r * r - d0_sq;
    double m = sqrt(max(0.0, dt) / (a * a + b * b));

    sol.push_back({x0 + b * m, y0 - a * m});
    sol.push_back({x0 - b * m, y0 + a * m});
    return true;
  }
}

bool circleLine(double r, Point center, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  double distCenter = t.a * center.x + t.b * center.y + t.c;

  Line newLine = {t.a, t.b, distCenter};
  vector<Point> localSol;
  if (!circleLine(r, newLine, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center.x, p.y + center.y});
  }
  return true;
}

bool circleCircle(double r1, double r2, Point c, vector<Point> &sol) {
  double dist = sqrt((c.x * c.x) + (c.y * c.y));
  double sumR = r1 + r2;

  if ((dist > r1 + r2 + EPS) || (dist < abs(r1 - r2) - EPS)) return false; // no intersection
  if (dist < EPS && abs(r1 - r2) < EPS) return false; //infinite solutions
  double a = -2 * c.x;
  double b = -2 * c.y;
  double C = (c.x * c.x) + (c.y * c.y) + (r1 * r1) - (r2 * r2);

  circleLine(r1, {a, b, C}, sol);

  return true;
}

// center1 is on 'origin' and center2 is shifted to a new relative posiiton (relative to Center1)
bool circleCircle(double r1, Point center1, double r2, Point center2, vector<Point> &sol) {
  Point relC2 = {center2.x - center1.x, center2.y - center1.y};

  vector<Point> localSol;

  if (!circleCircle(r1, r2, relC2, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center1.x, p.y + center1.y});
  }

  return true;
}

// POLYGON & AREA
void convex_hull (vector<Point>& a, bool include_collinear = false) {
  Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
  });

  sort (a.begin(), a.end(), [&p0] (const Point& a, const Point& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      // si son colineales, primero se mira el punto más cercano
      return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) < (p0.x - b.x ) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
    return o > 0;
    // o < 0 clockwise; o > 0 counterclockwise
  });


  if (include_collinear){
    int i = (int) a.size() - 1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin() + i + 1, a.end());
  }

  vector<Point> st;
  for (int i = 0; i < (int) a.size(); i++){
    // cambiar ccw - ordenar counterclockwise; cw - ordenar clockwise
    while (st.size() > 1 && !ccw(st[st.size() - 2], st.back(), a[i], include_collinear)) {
      st.pop_back();
    }
    st.push_back(a[i]);
  }

  // mirar los puntos duplicados
  if (!include_collinear && st.size() == 2 && st[0] == st[1]) {
    st.pop_back();
  }
  a = st;
}

double shoelace(const vector<Point>& points) {
  double area = 0.0;
  int n = points.size();
  int j = n - 1;

  for (int i = 0; i < n; i++) {
    area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
    j = i;
  }
  return abs(area / 2.0);
}


bool pointInPoly(Point p, const vector<Point>& poly) {
  bool inside = false;
  int n = poly.size();

  for (int i = 0, j = n - 1; i < n; j = i++) {
    // point on vertex
    if (abs(p.x - poly[i].x) < EPS && abs(p.y - poly[i].y) < EPS) return true;

    if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
      (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
      inside = !inside;
    }
  }
  return inside;
}

bool pointInPolyBorder(Point p, const vector<Point>& poly) {
  int n = poly.size();

  for (int i = 0; i < n; i++) {
    Point p1 = poly[i];
    Point p2 = poly[(i + 1) % n];
    if (onSegment(p, p1, p2)) return true;
  }

  return pointInPoly(p, poly);
}


//HELPERS
double safe_acos(double val) {
  if (val < -1.0) return acos(-1.0);
  if (val > 1.0) return acos(1.0);
  return acos(val);
}

Point simetrico(const Point &P, const Line &e) {
  Line eP = {-e.b, e.a, e.b * P.x - e.a * P.y};
  vector<Point> sol;
  lineLine(e, eP, sol);
  Point X = sol[0];
  Point P2 = {2 * X.x - P.x, 2 * X.y - P.y};
  return P2;
}

//with 3 sides
double heron (double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// with 3 points
double triangleArea(Point a, Point b, Point c) {
  return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Point p, q, t;
  while ((cin >> p.x >> p.y >> q.x >> q.y >> t.x >> t.y) && (p.x || p.y || q.x || q.y || t.x || t.y)) {
    int xmin = ceil(min({p.x, q.x, t.x}));
    int xmax = floor(max({(p.x), (q.x), (t.x)}));
    int ymin = min({ceil(p.y), ceil(q.y), ceil(t.y)});
    int ymax = max({floor(p.y), floor(q.y), floor(t.y)});
    vector<Point> poly = {p,q,t};
    int ans = 0;
    // cout << "x: " << xmin << " " << xmax << endl;
    // cout << "y: " << ymin << " " << ymax << endl;

    for (int i = max(1,xmin); i <= min(99, xmax); i++) {
      for (int j = max(1,ymin); j <= min(99, ymax); j++) {
        // cout << "point: " << i << " " << j << (pointInPoly({i*1.0,j*1.0}, poly) ? "true" : "false") << endl;
        ans += pointInPolyBorder({i*1.0,j*1.0}, poly);
      }
    }
    cout << setw(4) << ans << '\n';
  }
  return 0;
}
