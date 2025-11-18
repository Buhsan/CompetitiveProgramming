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

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.<<" "<<j.max_value<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.val<<" "<<a.max_value<<"} "; cout<<endl;

#define TESTCASES false

const ll MOD = 1e9 + 7;


struct Letter {
  int val, max_value;
};


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

  void update(int idx, T val) {
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

struct MaxSeqOp {
  using T = Letter;

  T operator()(T a, T b) const {
    PAIR(a);
    PAIR(b);
    // cout<<endl;
    Letter res;
    if (a.val == b.val && a.val == 1) res = {1, a.max_value+b.max_value};
    // else if (a.val != b.val && (a.val == 2 || b.val == 2) && (a.val == 1 || b.val == 1)) res = {1, }
    else res = {0, max(a.max_value, b.max_value)};
    PAIR(res);
    cout<<endl;
    return res;
  }


  T id() const {
    return {1,0};
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

void solve(int tt){
  int n, m;
  cin >> n >> m;

  vector<Letter> lt;
  REP(i,0,n) {
    char c;
    cin >> c;
    if (c == 'F') lt.push_back({1, 1});
    else lt.push_back({0, 0});
  }
  // P(1);
  SegTree<Letter, MaxSeqOp> segTree(lt);

  REP(i,0,m) {
    char c;
    int l, r;
    cin >> c;
    P(c);
    switch(c) {
      case 's':{
        cin >> l >> r;
        // P(1);
        PRINT("PRINT");
        cout << l << " " << r << endl;
        
        Letter let = segTree.query(l-1, r-1);
        PAIR(let);
        P(let.max_value);
        cout << endl;
        break;
      }
      case 'c': {
        cin >> l;
        Letter aux = {1 - lt[i].val, 1 - lt[i].max_value};
        PRINT("CHANGE");
        P(l);
        PAIR(aux)
        segTree.update(l, aux);
        break;
      }
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
