#include <bits/stdc++.h>

using namespace std;

struct Point2d {
  double x, y;
};

struct Point {
  double x, y;
  int i;
};

double dist(double x1, double y1, double x2, double y2) {
  return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

bool canEscape(const Point2d &gopher, const Point2d &dog, const Point &p) {
  double distDog = dist(p.x, p.y, dog.x, dog.y);
  double distGopher = dist(p.x, p.y, gopher.x, gopher.y);

  return distGopher <= (distDog / 2.0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  while (getline(cin, line)) {
    if (line.empty())
      continue;
    stringstream ss(line);
    int n;
    double x1, y1, x2, y2;
    ss >> n >> x1 >> y1 >> x2 >> y2;
    vector<Point> points;

    for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      points.push_back({x, y, i});
    }

    Point res = {INT_MAX, INT_MAX, INT_MAX};

    for (int i = 0; i < n; i++) {
      if (canEscape({x1, y1}, {x2, y2}, points[i]) && points[i].i < res.i) {
        res = points[i];
      }
    }

    if (res.x == INT_MAX && res.y == INT_MAX) {
      cout << "The gopher cannot escape.\n";
    } else {
      cout << "The gopher can escape through the hole at (" << fixed << setprecision(3) << res.x << "," << res.y << ").\n";
    }
  }

  return 0;
}
