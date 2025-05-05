#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define PLIST(list) cout << #list << ": "; for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define PRINT(v) cout << v << endl
#define P(v) cout << #v << ": " << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

const ll MOD = 1e9 + 7;


#define TESTCASES 0

bool iscollinear = false;

struct point {
  double x, y;
  bool operator == (const point& t) const {
    return x == t.x && y == t.y;
  }

  point operator - (const point& t) const {
    return {x - t.x, y - t.y};
  }
};


double cross(point a, point b) {
  return a.x*b.y - a.y * b.x;

}


int orientation(point a, point b, point c) {
  double v = cross(b-a, c-a); //cross product 2D de dos puntos
  // double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y); //doble area del triangulo - formula con determinante
  if (v < 0) return -1;
  if (v > 0) return +1;
  return 0;
}bool onSegment(point p, point q, point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

bool doIntersect(point p1, point q1, point p2, point q2) {
    int o1 = orientation(p1, q1, p2); //p1q1 y p2
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4) return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}
 
int isPointInPolygon(point p, const vector<point> &polygon) {
  int n = polygon.size();
 
  point extreme = {1e9, p.y};
  int count = 0, i = 0;
  do {
    int next = (i + 1) % n;
 
    if (doIntersect(polygon[i], polygon[next], p, extreme)) {
      if (orientation(polygon[i], p, polygon[next]) == 0) {
        return onSegment(polygon[i], p, polygon[next]) ? 2 : 0;
      }
      count++;
    }
    i = next;
  } while (i != 0);
  return count % 2 ? 1 : 0;
}

void solve(int tt){
  int n, m; cin >> n >> m;
  vector<point> poly;
  REP(i,0,n) {
    double x, y; cin >> x >> y;
    poly.push_back({x,y});
  }

  REP(i,0,m) {
    double x,y; cin >> x >> y;
    point p = {x,y};
    int ans = isPointInPolygon(p, poly);
    if (ans == 1) {
      cout << "INSIDE" << endl;
    }
    else if (ans == 2) {
      cout << "BOUNDARY" << endl;
    }
    else if (ans == 0) {
      cout << "OUTSIDE" << endl;
    }
  }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    if (TESTCASES) {
        int tt; cin >> tt;
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
