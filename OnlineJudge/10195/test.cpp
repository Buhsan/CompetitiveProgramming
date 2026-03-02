#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Line {
  long double a, b, c;
};

struct Point {
  long double x, y;
};

Line normalizeLine(Line r) {
  long double a = r.a, b = r.b, c = r.c;
  long double z = sqrt(a * a + b * b);
  if (z > EPS) {
    a /= z; b /= z; c /= z;
  }
  // Estandarizar signos
  if (a < -EPS || (abs(a) < EPS && b < -EPS)) {
    a = -a; b = -b; c = -c;
  }
  return {a, b, c};
}

Line getLine(Point p1, Point p2) {
  long double a = p2.y - p1.y;
  long double b = p1.x - p2.x;
  long double c = -a * p1.x - b * p1.y;
  return normalizeLine({a, b, c});
}

bool circleLine(long double r, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  long double a = t.a, b = t.b, c = t.c;
  // Distancia del centro (0,0) a la recta, simplificado porque trasladaste el problema
  long double x0 = (-a * c) / (a * a + b * b);
  long double y0 = (-b * c) / (a * a + b * b);
  long double d0_sq = (c * c) / ((a * a) + (b * b));

  if (d0_sq > r * r + EPS) {
    return false;
  } else if (abs(d0_sq - (r * r)) < EPS) {
    sol.push_back({x0, y0});
    return true;
  } else {
    long double dt = r * r - d0_sq;
    long double m = sqrt(max((long double)0.0, dt) / (a * a + b * b));
    sol.push_back({x0 + b * m, y0 - a * m});
    sol.push_back({x0 - b * m, y0 + a * m});
    return true;
  }
}

bool lineLine(Line l1, Line l2, vector<Point> &sol) {
  long double det = l1.a * l2.b - l2.a * l1.b;
  sol.clear();
  if (abs(det) < EPS) return false; // Paralelas
  long double x = (l2.c * l1.b - l1.c * l2.b) / det;
  long double y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back({x, y});
  return true;
}

bool circleCircle(long double r1, long double r2, Point c, vector<Point> &sol) {
  long double dist = sqrt((c.x * c.x) + (c.y * c.y));

  if (dist > r1 + r2 + EPS || dist < abs(r1 - r2) - EPS || (dist < EPS && abs(r1 - r2) < EPS)) 
    return false;

  long double a = -2 * c.x;
  long double b = -2 * c.y;
  long double C = (c.x * c.x) + (c.y * c.y) + (r1 * r1) - (r2 * r2);
  return circleLine(r1, {a, b, C}, sol);
}

// Intersección moviendo coordenadas relativas
bool circleCircle(long double r1, Point center1, long double r2, Point center2, vector<Point> &sol) {
  Point relC2 = {center2.x - center1.x, center2.y - center1.y};
  vector<Point> localSol;
  if (!circleCircle(r1, r2, relC2, localSol)) return false;
  for (Point p : localSol) {
    sol.push_back({p.x + center1.x, p.y + center1.y});
  }
  return true;
}

// Función de seguridad para acos
long double safe_acos(long double val) {
  if (val < -1.0) return acos(-1.0);
  if (val > 1.0) return acos(1.0);
  return acos(val);
}


double heron (double a, double b, double c) {
  double s = (a+b+c)/2.0;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long double a, b, c;

  while (cin >> a >> b >> c) {
    double semi = (a+b+c)/2.0;
    double area = heron(a,b,c);
    double ans = 0.000;
    if ((a < EPS || b < EPS || c < EPS) || semi < EPS) ans = 0.000;
    else if (a <= 0) ans = 0.000;
    else {
      ans = area/semi;
    }
    cout << "The radius of the round table is: " << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}
