#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
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

#define TESTCASES true 

const ll MOD = 1e9 + 7;

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

vector<pii> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

int mod(int num, int m) {
  return ((num % m) + m) % m == 0 ? m: ((num % m) + m) % m;
}

// void solve(int tt) {
//   int n, m, x;
//   cin >> n >> m >> x;
//   multiset<int> posibles;
//   posibles.insert(x);
//   REP (i, 0, m) {
//     int dist;
//     cin >> dist;
//     char c;
//     cin >> c;

//     if (c == '?') {
//       for (int posible : posibles) {
//         int izq = mod(posible + dist, n);
//         int der = mod(posible - dist, n);
//         q.push(izq);
//         q.push(der);
//       }
//     } else if (c == '0') {
//       for (int posible : posibles) {
//         q.push(mod(posible - dist, n));
//       }
//     } else {
//       for (int posible : posibles) {
//         q.push(mod(posible + dist, n));
//       }
//     }



//   }
// }

void solve(int tt){
  int n, m, x;
  cin >> n >> m >> x;
  int i = 1;
  int r; char c;
  queue<int> q;
  q.push(x);
  set<int> visited;
  REP(i,0,m) {
    queue<int> nq;
    visited.clear();
    cin >> r >> c;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      int a, b;
      a = mod(v+r,n);
      b = mod(v-r, n);
      if (c=='?'){
        // cout << "?: " << v << " " << a << " " << b << endl;
        if(!visited.count(a)) nq.push(a), visited.insert(a);
        if(!visited.count(b)) nq.push(b), visited.insert(b);
      }
      else if(c=='0'){
        // cout << "0: "<< v << " " << a << endl;
        if(!visited.count(a)) nq.push(a), visited.insert(a);
      }
      else {
        // cout << "1: " <<  v <<" "<< b << endl;
        if(!visited.count(b)) nq.push(b), visited.insert(b);
      }
    }
    q = nq;
    // cout<<endl;
  }
  PRINT(visited.size());
  PRINTLIST(visited);
}



/*
void solve(int tt) {
  int n, m, x;
  cin >> n >> m >> x;
  queue<int> q;
  q.push(x);
  set<int> visitados;
  for(int i = 0;i<m;i++){
    queue<int> q2 = q;
    q = queue<int>();
    int r;
    char c;
    cin >> r >> c;
    visitados.clear();
    while(!q2.empty()){
      int actual = q2.front();
      // visitados.insert(actual);
      q2.pop();
      int destiny1, destiny2;
      destiny1 = (((actual + r) % n) + n) % n == 0 ? n : (((actual+r) % n) + n) % n;
      destiny2 = (((actual - r) % n) + n) % n == 0 ? n : (((actual - r) % n) + n) % n;

      if(c == '?'){
        if (!visitados.count(destiny1)) q.push(destiny1), visitados.insert(destiny1);
        if (!visitados.count(destiny2)) q.push(destiny2), visitados.insert(destiny2);
      }
      else if(c == '1'){
        if (!visitados.count(destiny2)) q.push(destiny2), visitados.insert(destiny2);
      }
      else{
        if (!visitados.count(destiny1)) q.push(destiny1), visitados.insert(destiny1);
      }
    }
  }
  cout << visitados.size() << endl;
  for (int i : visitados) {
    cout << i << " ";
  }
  cout << endl;
}
*/

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
