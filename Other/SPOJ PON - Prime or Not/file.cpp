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
using u128 = __uint128_t;
using u64 = uint64_t;


#define TESTCASES 1


ll fpow (ll a, ll b, ll mod) {
  ll res = 1;
  a%=mod;
  while (b) {
    if (b%2) res = (res*a)%mod;
    a = (u128)a*a%mod;
    b/=2;
  }
  return res;
}


bool check_composite(ll n, ll a, ll d, int s) {
  ll x = fpow(a, d, n);
  if (x == 1 || x == n-1) {
    return false;
  }
  for (int r = 1; r<s; r++) {
    x = (u128)x*x%n;
    if (x == n-1)
      return false;
  }
  return true;
}


bool MillerRabin (ll n) {
  if (n < 2) 
    return false;
  int r = 0;
  ll d = n - 1;
  
  while (d%2 == 0) {
    d /= 2;
    r++;
  }

  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) 
      return true;
    if (check_composite(n, a, d, r)) {
      return false;
    }
  }
  return true;
}

void solve(int tt){
  ll n; cin >> n;
  cout << (MillerRabin(n) ? "YES" : "NO") << endl;
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
