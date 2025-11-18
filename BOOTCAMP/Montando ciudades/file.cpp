#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <unordered_map>
#include <functional>
#include <set>
#include <math.h>

// #include <bits/stdc++.h>;
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
#define PLIST(list) cout << #list << ": "; for (auto &elem : list) { cout << elem << " "; } cout<<endl;
// #define PLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
// #define FILL(list) for (auto elem : list) cin>>elem
// #define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

// #define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define PRINT(v) cout << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

#define TESTCASES false

int repString(string k, string search){
    int cnt = 0;
    REP(i,0,k.size()){
        if (k.substr(i,search.size()) == search) cnt++;
    }
    return cnt;
}

bool yn(bool cond, string tr = "YES", string fls = "NO") {
    if (cond) PRINT(tr);
    else PRINT(fls);
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

struct Road {
  ll a, b, d, id;
};


bool can(Road v, vector<Road> m) {
  REPLIST (i, m) {
    if (v.b == i.a) return false;
  }
  return true;
}

void make_set(vector<int> &nodoPadre, int v) {
  nodoPadre[v] = v;
}

int find_set(vector<int> &nodoPadre, int v) {
  if (v == nodoPadre[v]) return v;
  return find_set(nodoPadre, nodoPadre[v]);
}

void union_sets(vector<int> &nodoPadre, int a, int b) {
  a = find_set(nodoPadre, a);
  b = find_set(nodoPadre, b);
  if (a != b) nodoPadre[b] = a;
}


vll kruskal ( priority_queue<Road, vector<Road>, function<bool(Road, Road)>> pq, ll n) {
  vll res;
  // set<int> vertexes;
  vint list(n);
  REP(i,0,n) {
    make_set(list, i);
  }
  // P(2);
  while(!pq.empty()) {
    Road v = pq.top();
    pq.pop();
    // P(3);
    if (find_set(list, v.a) != find_set(list, v.b)) {
      // P(6);
      union_sets(list, v.a, v.b);
      // P(7);
      res.push_back(v.id);
      // P(8);
    }
    // P(9);
  }
  return res;
}

// vector<Road> kruskal ( priority_queue<Road, vector<Road>, function<bool(Road, Road)>> pq, int n) {
//   vector<Road> res;
//   set<int> vertexes;
//   while(!pq.empty()) {
//     Road v = pq.top();
//     pq.pop();

//     cout << v.a << " " << v.b << endl;
//     if (can(v, res) && vertexes.size()<n) {
//       // if (!vertexes.count(v.a)) vertexes.insert(v.a);
//       // if (!vertexes.count(v.b)) vertexes.insert(v.b);
//       // cout << v.a << " " << v.b << endl;
//       vertexes.insert(v.a);
//       vertexes.insert(v.b);
//       res.push_back(v);
//       
//     }
//   }
//   return res;
// }
//
//


void solve(int tt){
  int n, m;
  cin >> n >> m;
  priority_queue<Road, vector<Road>, function<bool(Road, Road)>> pq([](const Road &x, const Road &y){return x.d > y.d;});
  REP(i,0,m) {
    ll a,b,d;
    cin >> a>> b>> d;
    a--, b--;
    pq.push({a,b,d,i});
  }
  // PRINT(2);
  vll r = kruskal(pq, n);
  // PRINT(3);
  PRINT(r.size());
  REPLIST(j,r) {
    PRINT(j+1);
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
