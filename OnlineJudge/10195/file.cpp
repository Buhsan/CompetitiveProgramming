#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-9;

struct Line {
  long double a,b,c;
};

struct Point {
  long double x, y;
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
  long double a = r.a;
  long double b = r.b;
  long double c = r.c;
  long double z = sqrt(a*a + b*b);
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
  long double a = p2.y-p1.y;
  long double b = p1.x-p2.x;
  long double c = -a*p1.x - b*p1.y;
  return normalizeLine({a,b,c});
}

bool circleLine(long double r, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  long double a = t.a;
  long double b = t.b;
  long double c = t.c;
  long double x0 = (-a*c)/(a*a + b*b);
  long double y0 = (-b*c)/(a*a + b*b);
  long double d0_sq = (c*c) / ((a*a) + (b*b));

  if (d0_sq > r*r+EPS) {
    return false;
  } else if (abs(d0_sq - (r*r)) < EPS){
    sol.push_back({x0,y0});
    return true;
  } else {
    long double dt = r*r - d0_sq;
    long double m = sqrt(max((long double)0.0, dt) / (a*a+b*b));

    sol.push_back({x0 + b*m, y0 - a*m});
    sol.push_back({x0 - b*m, y0 + a*m});
    return true;
  }
}

bool lineLine(Line l1, Line l2, vector<Point> &sol) {
  long double det = l1.a * l2.b - l2.a * l1.b;
  sol = {};
  if (abs(det) < EPS) {
    // parallel case or same line case
    return false;
  }
  long double x = (l2.c * l1.b - l1.c * l2.b) / det;
  long double y = (l1.c * l2.a - l2.c * l1.a) / det;
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

bool circleLine(long double r, Point center, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  long double distCenter = t.a * center.x + t.b * center.y + t.c;

  Line newLine = {t.a, t.b, distCenter};
  vector<Point> localSol;
  if (!circleLine(r,newLine, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center.x, p.y + center.y});
  }
  return true;
}



bool circleCircle(long double r1, long double r2, Point c, vector<Point> &sol) {
  long double dist = sqrt((c.x*c.x) + (c.y*c.y));
  long double sumR = r1+r2;

  if ((dist > r1+r2 + EPS) || (dist < abs(r1-r2) - EPS)) return false; // no intersection
  if (dist < EPS && abs(r1-r2) < EPS) return false; //infinite solutions
  long double a = -2*c.x;
  long double b = -2*c.y;
  long double C = (c.x*c.x) + (c.y*c.y) + (r1*r1) - (r2*r2);

  circleLine(r1, {a,b,C}, sol);

  return true;
}


// center1 is on 'origin' and center2 is shifted to a new relative posiiton (relative to Center1)
bool circleCircle(long double r1, Point center1, long double r2, Point center2, vector<Point> &sol) {

  Point relC2 = {center2.x - center1.x, center2.y - center1.y};

  vector<Point> localSol;

  if (!circleCircle(r1,r2,relC2,localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center1.x, p.y + center1.y});
  }

  return true;
}
long double safe_acos(long double val) {
    if (val < -1.0) return acos(-1.0);
    if (val > 1.0) return acos(1.0);
    return acos(val);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long double a,b,c;
  while (cin >> a >> b >> c) {
    Point p = {0,0};
    Point q = {a,0};
    Point t = {0,0};
    vector<Point> sol;
    if((a < EPS || b < EPS || c < EPS) || !circleCircle(c,b,q,sol) || sol.empty()) { cout << "The radius of the round table is: " << fixed << setprecision(3) << 0.000 << endl; continue;}
    if (sol.size() == 1) {
      cout << "The radius of the round table is: " << fixed << setprecision(3) << 0.000 << endl; continue;
    }
    t = (sol[0].y > sol[1].y ? sol[0] : sol[1]);

    if (abs(t.y) < EPS) {
      cout << "The radius of the round table is: 67" << endl;
      continue;
    }


    // cout << t.x << " " << t.y << endl;
    long double alphaV = (t.x * q.x + t.y * q.y) / (sqrt((t.x * t.x) + (t.y * t.y)) * sqrt((q.x * q.x) + (q.y * q.y)));
    long double alpha = safe_acos(alphaV);
    // cout << "alpha: " << alpha << endl;
    Point t1 = {c * cos(alpha/2.0), c * sin(alpha/2.0)};
    // cout << "t1: " << t1.x << " " << t1.y << endl;


    pair<long double, long double> v1 = {p.x-q.x, p.y - q.y};
    // cout << "v1: " << v1.first << " " << v1.second << endl;
    pair<long double, long double> v2 = {t.x-q.x, t.y - q.y};
    // cout << "v2: " << v2.first << " " << v2.second << endl;

    long double betaV = (v1.first * v2.first + v1.second * v2.second) / (sqrt((v1.first * v1.first) + (v1.second * v1.second)) * sqrt((v2.first * v2.first) + (v2.second * v2.second)));
    long double beta = safe_acos(betaV);
    // cout << "beta: " << beta << endl;
    Point t2 = {a-(b * cos(beta/2.0)), b * sin(beta/2.0)};
    // cout << "t2: " << t2.x << " " << t2.y << endl;


    Line l1 = getLine(p,t1);
    Line l2 = getLine(q, t2);
    Line r = getLine(p,q);
    vector<Point> incentro;
    long double ans = 0.000;
    if (lineLine(l1,l2, incentro)) {
      Point center = incentro[0];
      ans = abs(r.a * center.x + r.b * center.y + r.c);
    }     
    cout << "The radius of the round table is: " << fixed << setprecision(3) << ans << endl;
  }
}
