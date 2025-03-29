#include <algorithm>
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

void solve(int tt){
  int n; 
  while (cin >> n && n) {
    vector<pii> a(n);
    REP(i,0,n) {
      int b; cin >> b;
      a[i] = {b,i};
    }
    // PPAIR(a);
    int sum = 0;
    REP(i,1,n){
      vector<pii> v(a.begin()+i, a.end());
      sort(v.begin(), v.end(), [](const pii &x, const pii &y) {return (x.first == y.first ? x.second < y.second : x.first < y.first);});
      int num = UPPER(v,a[i-1]);
      // P(num);
      // PAIR(v[num]);
      if (num == v.size() || v[num].first < a[i-1].first+1){
        // P((n-i));
        sum += (n-(i-1));
      }
      else {
        // P(v[num].second-(i-1));
        sum += (v[num].second-(i-1));
      }
    }
    cout << sum+1 << endl;
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
