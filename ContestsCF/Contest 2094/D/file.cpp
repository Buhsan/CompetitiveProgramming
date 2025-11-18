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


#define TESTCASES 1

void solve(int tt){
  string p; cin >> p;
  string s; cin >> s;
  int l1 = 0;
  vector<pair<char, int>> a;
  vector<pair<char, int>> b;
  int r1 = 0;
  int index = 0;
  int i = 0;
  while (i < p.size()) {
    char c = p[i];
    int j = i;
    while (j < p.size() && p[j] == c) j++;
    a.push_back({c, j-i});
    i = j;
  }
  i = 0;
  while (i < s.size()){
    char c = s[i];
    int j = i;
    while (j < s.size() && s[j] == c) j++;
    b.push_back({c, j-i});
    i = j;
  }

  bool res = true;
  // PPAIR(a);
  // PPAIR(b);

  if (a.size() != b.size()) {
    cout << "NO" << endl;
    return;
  }

  REP(i,0,a.size()) {
    if (a[i].first != b[i].first) {
      res = false;
      break;
    }
    int cnt1 = a[i].second;
    int cnt2 = b[i].second;
    if (cnt2 < cnt1|| cnt2 > cnt1*2) {
      res = false;
      break;
    }
  }

  // int id = 0;
  // bool res = true;
  // int cnt = 1;
  // // P(p);
  // // PLIST(a);
  // if (a.size() == 1) {
  //   set<int> c (s.begin(), s.end());
  //   if (c.size() > 1) res = false;
  //   else if ((a[0] <= s.size() && s.size() <= a[0]*2) && p[0] == s[0]) {
  //     res = true;
  //   }
  //   else res = false;
  // }
  // else { 
  //   REP(i,0,s.size()) {
  //     if (id > a.size()-1) {res = false; break;}
  //     if (i+1 >= s.size()) continue;
  //     if (s[i] == s[i+1]) cnt++;
  //     else if (s[i] != s[i+1]) {
  //       if (a[id] <= cnt && cnt <= a[id]*2) {
  //         cnt = 1;
  //         id++;
  //       }
  //       else {
  //         res = false;
  //         break;
  //       }
  //     }
  //   }
  // }
  cout << (res ? "YES" : "NO") << endl;

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
