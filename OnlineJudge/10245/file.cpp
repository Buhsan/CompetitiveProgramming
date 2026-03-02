#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double EPS = 1e-9;

struct Point {
  double x, y;
  bool operator==(const Point &p) const {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
  }

  bool operator<(const Point &p) const {
    if (abs(x - p.x) > EPS)
      return x < p.x - EPS;
    return y < p.y - EPS;
  }

  string toString() {
    stringstream out;
    out << "x: " << x << " y: " << y;
    return out.str();
  }

};

double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double bruteForce(vector<Point>& points, int left, int right) {
  double minDist = DBL_MAX;

  for (int i = left; i < right; i++) {
    // cout << "minDist: " << minDist << endl;
    for (int j = i+1; j < right; j++) {
      // cout << "i: " << i << " j: " << j << " dist: " << dist(points[i], points[j]) << endl;
      minDist = min(minDist, dist(points[i], points[j]));
    }
  }
  return minDist;
}

double checkCenter(vector<Point>& points, double d) {
  double minDist = d;
  sort(points.begin(), points.end(), [](const Point& a, const Point& b){
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });

  for (int i = 0; i < points.size(); i++) {
    for (int j = i+1; j < points.size() && (points[j].y - points[i].y < minDist); j++) {
      // if (points[j].y - points[i].y < minDist) break; 
      minDist = min(minDist, dist(points[i], points[j]));
    }
  }
  return minDist;
}


double calc(vector<Point>& points, int left, int right) {
  // cout << "left: " << left << " right: " << right << endl;
  int n = right - left;
  if (n <= 3) return bruteForce(points, left, right);

  int mid = (right - left) / 2 + left;
  Point midP = points[mid];

  double leftDist = calc(points, left, mid);
  double rightDist = calc(points, mid, right);
  double disti = min(leftDist, rightDist);

  vector<Point> center;
  center.reserve(right - left);

  for (int i = left; i < right; i++) {
    if (abs(points[i].x - midP.x) < disti) {
      center.push_back(points[i]);
    }
  }

  sort(center.begin(), center.end(), [](const Point& a, const Point& b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });

  return min(disti, checkCenter(center, disti));
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
      cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
      return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });

    // for (int i = 0; i < n; i++) {
    //   cout << points[i].toString() << endl;
    // }

    double minDist = calc(points, 0, n);

    if (minDist < 10000.0) {
      cout << fixed << setprecision(4) <<  minDist << '\n';
    } else {
      cout << "INFINITY\n";
    }
  }

  return 0;
}
