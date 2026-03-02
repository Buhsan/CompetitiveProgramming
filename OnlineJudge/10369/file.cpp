#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point{
  ll x, y;
};

double dist (Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int s, p; cin >> s >> p;
    vector<Point> points(p);
    for (int i = 0; i < p; i++) cin >> points[i].x >> points[i].y;
    for (int i = 0; i < p; i++) {
      for (int j = i + 1; j < p; j++) {
        cout << "point " << i << " point " << j << ": ";
        cout << dist(points[i], points[j]) << endl;;
      }
    }
  }

  return 0;
}
