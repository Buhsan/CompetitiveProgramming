// Pick
// A = I + B/2 - 1

// p = lcm * gcd ->  gcd = p / lcm
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point { ll x, y; };

ll boundary(const vector<Point>& p) {
  ll res = 0;
  for (int i = 0, n = p.size(); i < n; i++)
    res += __gcd(abs(p[i].x - p[(i+1)%n].x), abs(p[i].y - p[(i+1)%n].y));
  return res;
}

ll shoelace(const vector<Point>& p) {
  ll res = 0;
  for (int i = 0, n = p.size(); i < n; i++)
    res += p[i].x * p[(i+1)%n].y - p[(i+1)%n].x * p[i].y;
  return abs(res) / 2;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; 
  while (cin >> n && n) {
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    cout << shoelace(p) - boundary(p)/2 + 1 << '\n';
  }
  return 0;
}
