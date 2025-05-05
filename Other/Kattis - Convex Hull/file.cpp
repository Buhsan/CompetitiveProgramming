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
      // si son colineares, primero se mira el punto más cercano
        return (p0.x - a.x)* (p0.x - a.x) +  (p0.y - a.y)* (p0.y - a.y) < (p0.x - b.x)* (p0.x - b.x) + (p0.y - b.y)* (p0.y - b.y);
      return o < 0;
  });


  if (include_collinear){
    int i = (int) a.size()-1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }

  vector<point> st;
  for (int i=0; i < (int)a.size();  i++){
    // cambiar ccw por cw para ordenar clockwise
    while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.push_back(a[i]);
  }

  // mirar los puntos duplicados
  if (!include_collinear && st.size() == 2 && st[0] == st[1]) {
    st.pop_back();
  }
  a = st;
}







void solve(int tt){
  int n;
  while (cin >> n && n) {
    vector<point> a;
    for (int i = 0; i < n; i++) {
      double x,y; cin >> x >> y;
      a.push_back({x,y});
    }
    // convex hull
    convex_hull(a, false);
    
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
      cout << a[i].x << " " << a[i].y << endl;
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
