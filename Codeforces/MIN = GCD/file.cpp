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

#define SORTINCR(a) sort(a.begin(), a.end(), [](ll x, ll y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

const ll MOD = 1e9 + 7;

ll gcd (ll a, ll b) {
  if (!a) return b;
  return gcd(b%a, a);
}


#define TESTCASES 1

void solve(int tt){
  int n; cin >> n;
  vll a(n); FILL(a); SORTINCR(a);
  // PLIST(a);
  bool res = false;
  ll ans = 0;
  REP(i,1,n){
    if(a[i] % a[0] == 0) ans= gcd(ans, a[i]/a[0]);
  }
  res = (ans == 1);

  // if (n == 2) {
  //   res = (a[0] == a[1]);
  // }
  // else if (n == 3) {
  //   set<ll> s (a.begin(), a.end());
  //   if (s.size() <= 2) res = true;
  //   else {
  //     res = (a[2] % a[0] == 0 && a[1] % a[0] == 0);
  //   }
  // }
  // else {
  //   ll ans = 0;
  //   REP(i,1,n){
  //     if(a[i] % a[0] == 0) ans= gcd(ans, a[i]/a[0]);
  //   }
  //   res = (ans == 1);
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
