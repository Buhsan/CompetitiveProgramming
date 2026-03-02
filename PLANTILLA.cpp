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

const double EPS = 1e-9;

struct Line {
  double a,b,c;

  string toString() {
    stringstream out;
    out << "a: " << a << " b: " << b << " c: " << c;
    return out.str();
  }
};

struct Point {
  double x, y;

  bool operator < (const Point& t) const {
    if (abs(x - t.x) > EPS) return x < t.x;
    return y < t.y - EPS;
  }

  bool operator == (const Point& t) const {
    return abs(x - t.x) < EPS && abs(y - t.y) < EPS;
  }

  Point operator + (const Point& t) const { return {x + t.x, y + t.y}; }
  Point operator - (const Point& t) const { return {x - t.x, y - t.y}; }
  Point operator * (double t) const { return {x * t, y * t}; }
  Point operator / (double t) const { return {x / t, y / t}; }

  string toString() {
    stringstream out;
    out << "x: " << x << " y: " << y;
    return out.str();
  }
};

//PRIMITIVES

// Cross Product of two vectors (Origin -> a, Origin -> b)
// Returns the signed area of the parallelogram
double cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

// Cross Product of vectors (b-a) and (c-a)
// Returns value proportional to signed area of triangle abc
double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// 0: Collinear
// 1: Counter-Clockwise (Left Turn)
// -1: Clockwise (Right Turn)
int orientation(Point a, Point b, Point c) {
    double v = cross(a, b, c);
    if (abs(v) < EPS) return 0;
    return (v > EPS) ? 1 : -1;
}

double dist(const Point &a, const Point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}

// SEGMENT & LINES UTILS
Line normalizeLine(Line r) {
  double z = hypot(r.a, r.b);
  if (z > EPS) { r.a /= z; r.b /= z; r.c /= z; }
  if (r.a < -EPS || (abs(r.a) < EPS && r.b < -EPS)) {
    r.a = -r.a; r.b = -r.b; r.c = -r.c;
  }
  return r;
}

// Ax + By + C = 0;
Line getLine(Point p1, Point p2) {
  double a = p1.y - p2.y;
  double b = p2.x - p1.x;
  double c = -a * p1.x - b * p1.y;
  return normalizeLine({a, b, c});
}

bool onSegment(Point p, Point a, Point b) {
  if (orientation(a, b, p) != 0) return false;
  return p.x >= min(a.x, b.x) - EPS && p.x <= max(a.x, b.x) + EPS &&
  p.y >= min(a.y, b.y) - EPS && p.y <= max(a.y, b.y) + EPS;
}

// Distance from Point P to Line AB
// Also returns the projection point
double distPointLineProj(Point p, Point a, Point b, Point &proj) {
  double l2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (l2 < EPS) { proj = a; return dist(p, a); } // a == b case
  double t = dot(p - a, b - a) / l2;
  proj = a + (b - a) * t;
  return dist(p, proj);
}

double distPointLine(Point p, Point a, Point b) {
  Point c;
  return distPointLineProj(p, a, b, c);
}

// Distance from Point P to Segment AB
double distPointSegment(Point p, Point a, Point b) {
  double l2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  if (l2 < EPS) return dist(p, a);
  double t = dot(p - a, b - a) / l2;
  t = max(0.0, min(1.0, t));
  Point c = a + (b - a) * t;
  return dist(p, c);
}


// INTERSECTIONS
bool lineLine(Line l1, Line l2, vector<Point> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS) return false; // Parallel
  double x = (l1.b * l2.c - l2.b * l1.c) / det;
  double y = (l1.c * l2.a - l2.c * l1.a) / det;
  if (abs(x) < EPS) x = 0.0;
  if (abs(y) < EPS) y = 0.0;
  sol.push_back({x, y});
  return true;
}

// Returns:
// 0: Parallel (No intersection)
// 1: Unique Intersection (sol has 1 point)
// 2: Same Line (Infinite intersections)
int lineLinePro(Line l1, Line l2, vector<Point> &sol) {
  double det = l1.a * l2.b - l2.a * l1.b;
  if (abs(det) < EPS) {
    if (abs(l1.a * l2.c - l1.c * l2.a) < EPS && 
      abs(l1.b * l2.c - l1.c * l2.b) < EPS) {
      return 2; // Identical Lines (Infinite solutions)
    }
    return 0; //Parallel (No solution)
  }
  double x = (l1.b * l2.c - l2.b * l1.c) / det;
  double y = (l1.c * l2.a - l2.c * l1.a) / det;
  sol.push_back({x, y});
  return 1;
}

bool segmentSegment(Point a, Point b, Point c, Point d, vector<Point> &sol) {
  int o1 = orientation(a, b, c);
  int o2 = orientation(a, b, d);
  int o3 = orientation(c, d, a);
  int o4 = orientation(c, d, b);

  if (o1 != o2 && o3 != o4) {
    Line l1 = getLine(a, b);
    Line l2 = getLine(c, d);
    return lineLine(l1, l2, sol);
  }

  //Collinear overlap
  if (o1 == 0 && onSegment(c, a, b)) { sol.push_back(c); return true; }
  if (o2 == 0 && onSegment(d, a, b)) { sol.push_back(d); return true; }
  if (o3 == 0 && onSegment(a, c, d)) { sol.push_back(a); return true; }
  if (o4 == 0 && onSegment(b, c, d)) { sol.push_back(b); return true; }

  return false;
}

bool circleLine(double r, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  double a = t.a;
  double b = t.b;
  double c = t.c;
  double x0 = (-a * c) / (a * a + b * b);
  double y0 = (-b * c) / (a * a + b * b);
  double d0_sq = (c * c) / ((a * a) + (b * b));

  if (d0_sq > r * r + EPS) {
    return false;
  } else if (abs(d0_sq - (r * r)) < EPS){
    sol.push_back({x0, y0});
    return true;
  } else {
    double dt = r * r - d0_sq;
    double m = sqrt(max(0.0, dt) / (a * a + b * b));

    sol.push_back({x0 + b * m, y0 - a * m});
    sol.push_back({x0 - b * m, y0 + a * m});
    return true;
  }
}

bool circleLine(double r, Point center, Line t, vector<Point> &sol) {
  t = normalizeLine(t);
  double distCenter = t.a * center.x + t.b * center.y + t.c;

  Line newLine = {t.a, t.b, distCenter};
  vector<Point> localSol;
  if (!circleLine(r, newLine, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center.x, p.y + center.y});
  }
  return true;
}

bool circleCircle(double r1, double r2, Point c, vector<Point> &sol) {
  double dist = sqrt((c.x * c.x) + (c.y * c.y));
  double sumR = r1 + r2;

  if ((dist > r1 + r2 + EPS) || (dist < abs(r1 - r2) - EPS)) return false; // no intersection
  if (dist < EPS && abs(r1 - r2) < EPS) return false; //infinite solutions
  double a = -2 * c.x;
  double b = -2 * c.y;
  double C = (c.x * c.x) + (c.y * c.y) + (r1 * r1) - (r2 * r2);

  circleLine(r1, {a, b, C}, sol);

  return true;
}

// center1 is on 'origin' and center2 is shifted to a new relative posiiton (relative to Center1)
bool circleCircle(double r1, Point center1, double r2, Point center2, vector<Point> &sol) {
  Point relC2 = {center2.x - center1.x, center2.y - center1.y};

  vector<Point> localSol;

  if (!circleCircle(r1, r2, relC2, localSol)) return false;

  for (Point p : localSol) {
    sol.push_back({p.x + center1.x, p.y + center1.y});
  }

  return true;
}

// POLYGON & AREA
void monotoneChain(vector<Point>& points, bool collinear) {
  if (points.size() <= 2) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    return;
  }

  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end()); //only when sorted
  
  if (points.size() <= 2) return;

  int n = points.size();

  vector<Point> hull;
  hull.reserve(n+1); // avoids reallocations

  //Lower
  for (int i = 0; i < n; i++) {
    while(hull.size() > 1) {
      int ori = orientation(hull[hull.size()-2], hull.back(), points[i]);
      if (ori > 0 || (collinear && ori == 0)) break;
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }


  //Upper
  int upperSize = hull.size();
  for (int i = n-2; i >= 0; i--) {
    while (hull.size() > upperSize) {
      int ori = orientation(hull[hull.size()-2], hull.back(), points[i]);
      if (ori > 0 || (collinear && ori == 0)) break;
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }
  hull.pop_back();
  points = hull;
}

void graham(vector<Point> &points, bool collinear = false) {
  if (points.size() < 3) return;
  points.erase(unique(points.begin(), points.end()), points.end());

  // all collinear check
  // if (allCollinear(points)) {
  //   sort(points.begin(), points.end());
  //   if (!collinear) {
  //     points = {points.front(), points.back()};
  //     if (points[0] == points[1]) points.pop_back();
  //   }
  //   return;
  // }

  vector<Point>::iterator mini_it = min_element(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });

  iter_swap(points.begin(), mini_it);
  Point mini = points[0];


  sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
    double ori = orientation(mini, a, b);
    if (ori == 0) {
      return dist(mini, a) < dist(mini, b);
    }
    return ori > 0;
  });

  if (collinear) {
    int i = (int)points.size() - 1;
    while (i >= 1 && orientation(mini, points[i], points[i-1]) == 0) {
      i--;
    }
    reverse(points.begin()+i, points.end());
  }

  vector<Point> st;
  for (int i = 0; i < (int)points.size(); i++) {
    while (st.size() > 1) {
      double ori = orientation(st[st.size()-2], st.back(), points[i]);
      if (ori > 0 || (collinear && ori == 0)) break;
      st.pop_back();
    }
    st.push_back(points[i]);
  }

  //duplicate check
  if (!collinear && st.size() == 2 && st[0] == st[1]) {
    st.pop_back();
  }
  points = st;    
}


double shoelace(const vector<Point>& points) {
  double area = 0.0;
  int n = points.size();
  int j = n - 1;

  for (int i = 0; i < n; i++) {
    area += (points[j].x + points[i].x) * (points[j].y - points[i].y);
    j = i;
  }
  return abs(area / 2.0);
}


bool pointInPoly(Point p, const vector<Point>& poly) {
  bool inside = false;
  int n = poly.size();

  for (int i = 0, j = n - 1; i < n; j = i++) {
    // point on vertex
    if (abs(p.x - poly[i].x) < EPS && abs(p.y - poly[i].y) < EPS) return true;

    if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
      (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
      inside = !inside;
    }
  }
  return inside;
}

bool pointInPolyBorder(Point p, const vector<Point>& poly) {
  int n = poly.size();

  for (int i = 0; i < n; i++) {
    Point p1 = poly[i];
    Point p2 = poly[(i + 1) % n];
    if (onSegment(p, p1, p2)) return true;
  }

  return pointInPoly(p, poly);
}


//HELPERS
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

//with 3 sides
double heron (double a, double b, double c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// with 3 points
double triangleArea(Point a, Point b, Point c) {
  return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

ll fastPow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

ll modExp(ll base, ll exp, ll mod) {
  ll result = 1;
  base %= mod;

  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;

    base = (base * base) % mod;
    exp /= 2;
  }

  return result;
}


ll bincof(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= ((n - i)%MOD);
        res /= ((i + 1)%MOD);
    }
    return res;
}



ll bincof_dp(ll n, ll k, vector<vector<ll>> &dp) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    ll a = bincof(n - 1, k - 1);
    ll b = bincof(n - 1, k);
    return dp[n][k] = a + b;
}




template <typename T, typename Op>
class SegTree {
public:
  vector<T> tree;
  int n;
  Op op;

  SegTree(const vector<T> & v) {
    n = v.size();
    tree.resize(4 * n);

    build(v, 0, 0, v.size() - 1);
  }

  void build(const vector<T>& arr, int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;
      
      build(arr, leftChild, start, mid);
      build(arr, rightChild, mid + 1, end);

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }

  T query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  T query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      return op.id();
    }
    if (L <= start && end <= R) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;

    T leftResult = query(leftChild, start, mid, L, R);
    T rightResult = query(rightChild, mid + 1, end, L, R);

    return op(leftResult, rightResult);
  }

  void update(int idx, int val) {
    update(0, 0, n - 1, idx, val);
  }

  void update(int node, int start, int end, int idx, T val) {
    if (start == end) {
      tree[node] = val;
    } else {
      int mid = (start + end) / 2;
      int leftChild = 2 * node + 1;
      int rightChild = 2 * node + 2;

      if (start <= idx && idx <= mid) {
        update(leftChild, start, mid, idx, val);
      } else {
        update(rightChild, mid + 1, end, idx, val);
      }

      tree[node] = op(tree[leftChild], tree[rightChild]);
    }
  }
};

struct SumOp {
  using T = ll;

  T operator()(T a, T b) const {
    return a + b;
  }

  T id() const {
    return 0;
  }
};

struct MinOp {
  using T = ll;

  T operator()(T a, T b) const {
    return min(a, b);
  }

  T id() const {
    return LLONG_MAX;
  }
};


/*
template<typename T>
void make_set(vector<T> &dsu, T v) {
  dsu[v] = v;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
 if (v == dsu[v]) return v;
  return find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) dsu[b] = a;
}
*/

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
  }
}

// int __lcm(int a, int b) {
//   return (a*b) / __gcd(a, b);
// }

bool yn(bool cond) {
  cond ? PRINT("YES") : PRINT("NO");
  return cond;
}

int prefix_sum(vint a, int l, int r){
    // l, r -> [0,+inf]
    vint pref_sum(a.size());
    pref_sum[0] = a[0];
    REP(i, 1, a.size()){
        pref_sum[i] = pref_sum[i - 1] + a[i];
    }
    return pref_sum[r] - (l == 0 ? 0:pref_sum[l-1]);
}

vector<pii> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

#define TESTCASES 0

void solve(int tt){
    //CODE
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
