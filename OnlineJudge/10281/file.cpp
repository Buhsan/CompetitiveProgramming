// #include <bits/stdc++.h>
// #include <iomanip>
// #include <sstream>
// using namespace std;

// typedef long long int ll;
// typedef vector<ll> vll;
// typedef vector<int> vint;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;

// #define REP(i, a, b) for (int i = a; i < b; ++i)
// #define REPV(i, a, b) for (int i = a; i >= b; --i)
// #define PLIST(list) cout << #list << ": "; for (auto &elem : list) { cout << elem << " "; } cout<<endl;
// #define FILL(list) for (auto &elem : list) cin>>elem
// #define REPLIST(i, list) for (auto i : list)

// // #define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
// #define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
// // #define PRINT(...) ((cout << ... << " "), cout << endl)
// #define PRINT(v) cout << v << endl
// #define P(v) cout << #v << ": " << v << endl
// // #define P(...) ((cout << ((cout << #__VA_ARGS__ << " = ") , ... , (cout << __VA_ARGS__ << " "))), cout << endl)



// #define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
// #define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
// #define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

// #define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
// #define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

// #define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
// #define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

// #define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
// #define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;


// const ll MOD = 1e9 + 7;


// ll fastPow(ll a, ll b) {
//   ll res = 1;
//   while (b > 0) {
//     if (b & 1) res = res * a;
//     a = a * a;
//     b >>= 1;
//   }
//   return res;
// }

// ll modExp(ll base, ll exp, ll mod) {
//   ll result = 1;
//   base %= mod;

//   while (exp > 0) {
//     if (exp % 2 == 1) result = (result * base) % mod;

//     base = (base * base) % mod;
//     exp /= 2;
//   }

//   return result;
// }

// template <typename T, typename Op>
// class SegTree {
// public:
//   vector<T> tree;
//   int n;
//   Op op;

//   SegTree(const vector<T> & v) {
//     n = v.size();
//     tree.resize(4 * n);

//     build(v, 0, 0, v.size() - 1);
//   }

//   void build(const vector<T>& arr, int node, int start, int end) {
//     if (start == end) {
//       tree[node] = arr[start];
//     } else {
//       int mid = (start + end) / 2;
//       int leftChild = 2 * node + 1;
//       int rightChild = 2 * node + 2;
//       
//       build(arr, leftChild, start, mid);
//       build(arr, rightChild, mid + 1, end);

//       tree[node] = op(tree[leftChild], tree[rightChild]);
//     }
//   }

//   T query(int l, int r) {
//     return query(0, 0, n - 1, l, r);
//   }

//   T query(int node, int start, int end, int L, int R) {
//     if (R < start || end < L) {
//       return op.id();
//     }
//     if (L <= start && end <= R) {
//       return tree[node];
//     }

//     int mid = (start + end) / 2;
//     int leftChild = 2 * node + 1;
//     int rightChild = 2 * node + 2;

//     T leftResult = query(leftChild, start, mid, L, R);
//     T rightResult = query(rightChild, mid + 1, end, L, R);

//     return op(leftResult, rightResult);
//   }

//   void update(int idx, int val) {
//     update(0, 0, n - 1, idx, val);
//   }

//   void update(int node, int start, int end, int idx, T val) {
//     if (start == end) {
//       tree[node] = val;
//     } else {
//       int mid = (start + end) / 2;
//       int leftChild = 2 * node + 1;
//       int rightChild = 2 * node + 2;

//       if (start <= idx && idx <= mid) {
//         update(leftChild, start, mid, idx, val);
//       } else {
//         update(rightChild, mid + 1, end, idx, val);
//       }

//       tree[node] = op(tree[leftChild], tree[rightChild]);
//     }
//   }
// };

// struct SumOp {
//   using T = ll;

//   T operator()(T a, T b) const {
//     return a + b;
//   }

//   T id() const {
//     return 0;
//   }
// };

// struct MinOp {
//   using T = ll;

//   T operator()(T a, T b) const {
//     return min(a, b);
//   }

//   T id() const {
//     return LLONG_MAX;
//   }
// };


// void make_set(vector<int> &nodoPadre, int v) {
//   nodoPadre[v] = v;
// }

// int find_set(vector<int> &nodoPadre, int v) {
//   if (v == nodoPadre[v]) return v;
//   return find_set(nodoPadre, nodoPadre[v]);
// }

// void union_sets(vector<int> &nodoPadre, int a, int b) {
//   a = find_set(nodoPadre, a);
//   b = find_set(nodoPadre, b);
//   if (a != b) nodoPadre[b] = a;
// }

// int repString(string k, string search){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,search.size()) == search) cnt++;
//     }
//     return cnt;
// }

// // int __lcm(int a, int b) {
// //   return (a*b) / __gcd(a, b);
// // }

// bool yn(bool cond) {
//   cond ? PRINT("YES") : PRINT("NO");
//   return cond;
// }

// int prefix_sum(vint a, int l, int r){
//     // l, r -> [0,+inf]
//     vint pref_sum(a.size());
//     pref_sum[0] = a[0];
//     REP(i, 1, a.size()){
//         pref_sum[i] = pref_sum[i - 1] + a[i];
//     }
//     return pref_sum[r] - (l == 0 ? 0:pref_sum[l-1]);
// }

// vector<pii> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

// #define TESTCASES 0

// double getTime(string s) {
//   double hours;
//   stringstream temp(s);
//   string aux;
//   int i = 0;
//   while(getline(temp, aux, ':') && i <= 2) {
//     int n = stoi(aux);
//     if (i==0) hours += n;
//     else if (i == 1) hours += ((double)n/60.0);
//     else if (i == 2) hours += ((double)n/3600.0);
//     i++;
//   }
//   return hours;
// }


// void solve(int tt){
//   string s;
//   double initTime = 0;
//   double initVel = 0;
//   double dist = 0;
//   while(getline(cin,s)) {
//     vector<string> input;
//     stringstream in(s);
//     string aux;
//     while(in >> aux) {
//       input.push_back(aux);
//     }
//     double t = getTime(input[0]);
//     dist += (abs(initTime-t)) * initVel;
//     initTime = t;
//     if (input.size() == 2) {
//       initVel = stod(input[1]);
//     }
//     else if (input.size() == 1) {
//       cout << input[0] << " " << fixed << setprecision(2) << dist << " km"<<endl;
//     }
//     P(initVel);
//   }
// }



// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     
//     if (TESTCASES) {
//         int tt; cin >> tt;
//         REP(i, 1, tt+1) {
//             solve(i);
//         }
//     } else solve(1);

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string line;
  double travelled = 0;
  double lastTime = -1;
  double factor = 1000.0f / (60.0f * 60.0f);
  double speed = 0;
  while (getline(cin, line)) {
    bool query = true;
    string time, change;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] == ' ') {
        query = false;
        time = line.substr(0, i);
        change = line.substr(i + 1, line.size() - (i + 1));
      }
    }

    if (query) {
      time = line;
    }

    double seconds = stoi(time.substr(0, 2)) * 60 * 60 + stoi(time.substr(3, 2)) * 60 + stoi(time.substr(6, 2));

    if (lastTime != -1) {
      double elapsedTime = seconds - lastTime;
      travelled += elapsedTime * speed;
    }

    if (query) {
      cout << time << " " << fixed << setprecision(2) << (travelled / 1000.0f) << " km" << endl;
    }

    if (!change.empty()) {
      speed = stoi(change) * factor;
    }

    lastTime = seconds;
  }
  return 0;
}
