#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Line {
  double a,b,c;
};

struct Point {
  double x, y;
  bool operator == (const Point& t) const {
    return x == t.x && y == t.y;
  }

  Point operator - (const Point& t) const {
    return {x - t.x, y - t.y};
  }
};

// is P on segment of A and B
bool onSegment(Point p, Point a, Point b) {
  return p.x >= min(a.x, b.x) - EPS && p.x <= max(a.x, b.x) + EPS &&
  p.y >= min(a.y, b.y) - EPS && p.y <= max(a.y, b.y) + EPS;
}


double cross(Point a, Point b) {
  return a.x*b.y - a.y * b.x;

}

int orientation(Point a, Point b, Point c) {
  double v = cross(b-a, c-a); //cross product 2D de dos puntos
  // double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); //doble area del triangulo - formula con determinante
  if (v < 0) return -1;
  if (v > 0) return +1;
  return 0;
}


bool cw (Point a, Point b, Point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool ccw (Point a, Point b, Point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o > 0 || (include_collinear && o == 0);
}

bool collinear (Point a, Point b, Point c) {return orientation(a,b,c) == 0;}


void convex_hull (vector<Point>& a, bool include_collinear = false) {
  Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
  });

  sort (a.begin(), a.end(), [&p0] (const Point& a, const Point& b) {
    int o = orientation(p0, a, b);
    if (o == 0)
      // si son colineales, primero se mira el punto más cercano
      return (p0.x - a.x)* (p0.x - a.x) +  (p0.y - a.y)* (p0.y - a.y) < (p0.x - b.x)* (p0.x - b.x) + (p0.y - b.y)* (p0.y - b.y);
    return o > 0;
    // o < 0 - clockwise; o > 0 counterclockwise
  });


  if (include_collinear){
    int i = (int) a.size()-1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }

  vector<Point> st;
  for (int i=0; i < (int)a.size();  i++){
    // cambiar ccw - ordenar counterclockwise; cw - ordenar clockwise
    while (st.size() > 1 && !ccw(st[st.size()-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }

  // mirar los puntos duplicados
  if (!include_collinear && st.size() == 2 && st[0] == st[1]) {
    st.pop_back();
  }
  a = st;
}

double shoelace (const vector<Point>& points) {
  double area = 0.0;
  int n = points.size();
  int j = n - 1;

  for (int i = 0; i < n; i++) {
    area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
    j = i;
  }
  return abs(area/2.0);
}


Line normalizeLine(Line r) {
  double a = r.a;
  double b = r.b;
  double c = r.c;
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

// Ax + By + C = 0;
Line getLine(Point p1, Point p2) {
  double a = p2.y-p1.y;
  double b = p1.x-p2.x;
  double c = -a*p1.x - b*p1.y;
  return normalizeLine({a,b,c});
}

bool circleLine(double r, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
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
    double m = sqrt(max(0.0, dt) / (a*a+b*b));

    sol.push_back({x0 + b*m, y0 - a*m});
    sol.push_back({x0 - b*m, y0 + a*m});
    return true;
  }
}

bool lineLine(Line l1, Line l2, vector<Point> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  sol = {};
  if (abs(det) < EPS) {
    // parallel case or same line case
    return false;
  }
  double x = (l2.c * l1.b - l1.c * l2.b) / det;
  double y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back({x,y});
  return true;
}

// AB intersect with CD?
bool interSegment(Point a, Point b, Point c, Point d, vector<Point> &sol) {
  Line l1 = getLine(a,b);
  Line l2 = getLine(c,d);

  vector<Point> soli;
  if (lineLine(l1, l2, soli)) {
    Point p = soli[0];
    if (onSegment(p, a, b) && onSegment(p, c, d)) {
      sol.push_back(p);
      return true;
    }
    return false;
  }
  return false;
}

bool circleLine(double r, Point center, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  double distCenter = t.a * center.x + t.b * center.y + t.c;

  Line newLine = {t.a, t.b, distCenter};
  vector<Point> localSol;
  if (!circleLine(r,newLine, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center.x, p.y + center.y});
  }
  return true;
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


// center1 is on 'origin' and center2 is shifted to a new relative posiiton (relative to Center1)
bool circleCircle(double r1, Point center1, double r2, Point center2, vector<Point> &sol) {

  Point relC2 = {center2.x - center1.x, center2.y - center1.y};

  vector<Point> localSol;

  if (!circleCircle(r1,r2,relC2,localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center1.x, p.y + center1.y});
  }

  return true;
}

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

double dist(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  cin.ignore();

  string line;
  getline(cin, line);

  int c = 0;
  while (t--) {
    line = "x";

    vector<Point> pts;
    while (true) {
      getline(cin, line);
      if (line.empty()) break;

      stringstream ss(line);

      Point p;
      ss >> p.x >> p.y;

      pts.push_back(p);
    }

    int ans = 0;

    int n = pts.size();


    if (n == 1) {
      ans = 1;
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          vector<Point> sol;

          circleCircle(2.5, pts[i], 2.5, pts[j], sol);

          for (Point &p : sol) {
            int curr = 0;
            for (int k = 0; k < n; k++) {

              double distSq = (p.x - pts[k].x) * (p.x - pts[k].x) + (p.y - pts[k].y) * (p.y - pts[k].y);

              if (distSq <= 2.5 * 2.5 + EPS) {
                curr++;
              }
            }

            ans = max(ans, curr);

          }

        }
      }

      for (Point &p : pts) {
        int curr = 0;
        for (int k = 0; k < n; k++) {

          double distSq = (p.x - pts[k].x) * (p.x - pts[k].x) + (p.y - pts[k].y) * (p.y - pts[k].y);

          if (distSq <= 2.5 * 2.5) {
            curr++;
          }
        }

        ans = max(ans, curr);

      }
    }

    if (c) cout << "\n";
    cout << ans << "\n";
    c++;
  }

  return 0;
}
