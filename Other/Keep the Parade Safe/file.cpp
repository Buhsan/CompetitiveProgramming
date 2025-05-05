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
}


bool cw (point a, point b, point c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool ccw (point a, point b, point c, bool include_collinear) {
  int o = orientation(a, b, c);
  if (o == 0) iscollinear = true;
  return o > 0 || (include_collinear && o == 0);
}

bool collinear (point a, point b, point c) {return orientation(a,b,c) == 0;}


void convex_hull (vector<point>& a, bool include_collinear = false) {
  point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
      return a.y == b.y ? a.x < b.x : a.y < b.y;
  });

  sort (a.begin(), a.end(), [&p0] (const point& a, const point& b) {
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

  vector<point> st;
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
 
bool onSegment(point p, point q, point r) {
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
 
bool isPointInPolygon(point p, const vector<point> &polygon) {
  int n = polygon.size();
 
  point extreme = {1e9, p.y};
  int count = 0, i = 0;
  do {
    int next = (i + 1) % n;
 
    if (doIntersect(polygon[i], polygon[next], p, extreme)) {
      if (orientation(polygon[i], p, polygon[next]) == 0) {
        return onSegment(polygon[i], p, polygon[next]);
      }
      count++;
    }
    i = next;
  } while (i != 0);
  return count % 2 == 1;
}

void solve(int tt){
  int n; cin >> n;
  vector<point> a;
  REP(i,0,n) {
    double x,y; cin >> x >> y;
    a.push_back({x,y});
  }
  int num = a.size();
  vector<point> b (a.begin(), a.end());
  convex_hull(a);
  ll res = 0;
  int t; cin >> t;
  P(a.size());
  REP(i,0,a.size()) {
    cout << a[i].x << " " << a[i].y << endl;
  }
  cout << endl; 
  REP(i,0,t) {
    double x,y; cin >> x >> y;
    if (!iscollinear) {
      point p = {x,y};
      // cout << p.x << " " << p.y << endl;;
      if (isPointInPolygon(p, a)) {
        res++;
        cout << p.x << " " << p.y << endl;;
      } 
    }
  }
  cout << res << endl;
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
