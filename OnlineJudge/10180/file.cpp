#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double EPS = 1e-9;

struct Line {
  double a,b,c;
};

struct Point{
  double x,y;
};

// Ax + By + C = 0;
Line getLine(Point p1, Point p2) {
  double a = p2.y-p1.y;
  double b = p1.x-p2.x;
  double c = -a*p1.x - b*p1.y;

  double z = sqrt(a*a + b*b);
  if (z > EPS) {
    a /= z;
    b /= z;
    c /= z;
  }

  if (a < -EPS || abs(a) < EPS && b < -EPS) {
    a = -a;
    b = -b;
    c = -c;
  }

  return {a,b,c};
}

bool circleLine(double r, Line t, vector<Point> &sol) {
  double a = t.a;
  double b = t.b;
  double c = t.c;
  double x0 = (-a*c)/(a*a + b*b);
  double y0 = (-b*c)/(a*a + b*b);
  double d0_sq = (c*c) / ((a*a) + (b*b));

  if (d0_sq > r*r+EPS) {
    return false;
  } else if (abs(d0_sq - (r*r)) < EPS){
    sol.push_back({x0,y0});
    return true;
  } else {
    double dt = r*r - d0_sq;
    double m = sqrt(dt / (a*a+b*b));

    sol.push_back({x0 + b*m, y0 - a*m});
    sol.push_back({x0 - b*m, y0 + a*m});
    return true;
  }
}

bool circleCircle(double r1, double r2, Point c, vector<Point> &sol) {

  double dist = sqrt((c.x*c.x) + (c.y*c.y));
  double sumR = r1+r2;

  if ((dist > r1+r2 + EPS) || (dist < abs(r1-r2) - EPS)) return false; // no intersection
  if (dist < EPS && abs(r1-r2) < EPS) return false; //infinite solutions
  double a = -2*c.x;
  double b = -2*c.y;
  double C = (c.x*c.x) + (c.y*c.y) + (r1*r1) - (r2*r2);

  circleLine(r1, {a,b,C}, sol);

  return true;
}
double getArcLength(Point a, Point b, double r) {
  double angleA = atan2(a.y, a.x);
  double angleB = atan2(b.y, b.x);

  double theta = abs(angleA - angleB);

  if (theta > M_PI) {
    theta = 2 * M_PI - theta;
  }
  return r * theta;
}

double dist(Point p, Point q) {
  return sqrt((p.x-q.x)*(p.x-q.x) + ((p.y-q.y)*(p.y-q.y)));
}

vector<Point> tagency(Point p, double r1) {
  double dist = sqrt((p.x*p.x) + (p.y*p.y));
  double r2 = dist / 2.0;
  vector<Point> sol;
  circleCircle(r1, r2, {p.x/2.0, p.y/2.0}, sol);
  return sol;
}

// void sortPoint(Point p, vector<Point> &tags) {
//   double ang1 = atan2(tags[0].y, tags[0].x);
//   double ang2 = atan2(tags[1].y, tags[1].x);
//
//   if (ang1 > ang2) swap(tags[0], tags[1]);
// }

bool onSegment(Point p, Point q, Point s) {
  return s.x >= min(p.x, q.x) - EPS && s.x <= max(p.x, q.x) + EPS &&
         s.y >= min(p.y, q.y) - EPS && s.y <= max(p.y, q.y) + EPS;
}

// bool onSegment(Point p, Point q, vector<Point> v) {
//   int n = v.size();
//   for (int i = 0; i < n; i++) {
//     if (!onSegment(p, q, v[i])) return false;
//   }
//   return true;
// }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t;
  while (t--) {
    Point p, q;
    double r1;
    cin >> p.x >> p.y >> q.x >> q.y >> r1;

    Line l = getLine(p, q);
    vector<Point> sol;
    double res = 0;
    bool blocked = false;
    if (circleLine(r1, l, sol)) {
      for (Point s : sol) {
        if (onSegment(p, q, s)) {
          blocked = true;
        }
      }
    }

    if (blocked) {
      double d1 = sqrt((p.x*p.x) + (p.y*p.y));
      double d2 = sqrt((q.x*q.x) + (q.y*q.y));

      double tan1 = sqrt(d1*d1 - (r1*r1));
      double tan2 = sqrt(d2*d2 - (r1*r1));


      double total = abs(atan2(p.y, p.x) - atan2(q.y, q.x));

      if (total > M_PI) total = 2 * M_PI - total;


      double arc_angle = total - acos(r1/d1) - acos(r1/d2);
      if (arc_angle < 0) arc_angle = 0;

      res = tan1+tan2+(r1*arc_angle);
    } else {
      res = dist(p, q);
    }
    cout << fixed << setprecision(3) << res << '\n';
  }
  return 0;
}
