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


void change(string reg, map<string, string> &registers, int type) {
  // if (!registers.count(reg)) registers[reg] = "0";
  // registers[reg] = to_string(stoi(registers[reg]) + type);
  char c = registers[reg][0];
  c = c + type;
  string res (1, c);
  registers[reg] = res;
}


void solve(int tt){
  int n;
  cin >> n;
  string s;
  vector<pair<int,string>> vs;
  int id = 0;
  REP (i,0,n+1) {
    getline(cin, s);
    // P(s);
    if (s != "") vs.push_back({id++,s});
  }
  int input_num;
  cin >> input_num;
  // P(input_num);
  vector<char> input_str(input_num);
  // REP (i,0,input_num+1) {
  //   char c;
  //   P(i);
  //   if (i==0) cin.get(c), PRINT(1), P(c);
  //   else if (i > 0) cin.get(c), P(c);
  //   // cin >> input_str[i];
  //   // P(input_str[i]);
  // }
  P(input_num);
  cin.ignore();
  char c;
  int q = 0;
  while(cin.get(c) && q < input_num+2) {
    if(c == '\0') PRINT("EMPTY");
    P(c);
    q++;
  }
  // cin>> aux;
  // P(aux);
  // REP(i,0, input_num+1) {
  //   if (i == 0) getline(cin,aux);
  //   if (i > 0){
  //     getline(cin,aux);
  //     P(aux);
  //     P(aux.size());
  //     input_str.push_back(aux);
  //   }
  // }
  int input_i = 0;
  int input_j = 0;
  int index = 0;
  map<string, string> registers;
  stack<int> st_dir;
  // registers["0"] = 0;
  while(vs[index].second != "halt"){
    stringstream temp(vs[index].second);
    vector<string> instr;
    string in;
    int i = 0;
    while(temp >> in) {
      instr.push_back(in);
    }
    // PLIST(instr);
    if(instr[0] == "inc"){
      change(instr[1], registers, 1);
      // registers[instr[1]] = to_string(stoi(registers[instr[1]]) + 1);
      index++;
    }
    else if(instr[0] == "dec") {
      if (!registers.count(instr[1])) registers[instr[1]] = "0";
      if (registers[instr[1]] != "0") change(instr[1], registers, -1), index++;
      else if (registers[instr[1]] == "0") index = stoi(instr[2]);
    }
    else if(instr[0] == "inp") {
      // if (input_str.size() > 1 &&  input_j == input_str[input_i].size() - 1) input_i++, input_j = 0;
      // registers[instr[1]] = input_str[input_i][input_j];
      // P(input_str[input_i][input_j]);
      if (input_j >= input_num) registers[instr[1]] = "";
      else registers[instr[1]] = input_str[input_j];
      // P(registers[instr[1]]);
      // cout << registers[instr[1]] << '\n';
      input_j++;
      index++;
    }
    else if(instr[0] == "call") {
      st_dir.push(index+1);
      index = stoi(instr[1]);
    }
    else if(instr[0] == "ret") {
      int dir = st_dir.top();
      st_dir.pop();
      index = dir;
    }
    else if (instr[0] == "print") {
      // PRINT(instr[1]);
      // cout<<instr[1]<<": "<< registers[instr[1]]<<endl;
      // cout<<registers[instr[1]];
      index++;
      // cout<<endl;
    }
  }
  // REPLIST(i,registers){
  //   PAIR(i);
  // }
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
