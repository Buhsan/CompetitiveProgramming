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

const ll MAX_N = 1e5;

vll fact(MAX_N+1);


ll fpow (ll a, ll b, ll mod) {
  ll res = 1;
  while (b > 0) {
    if (b%2) res = (res * a)%mod;
    a = (a*a)%mod;
    b /= 2;
  }
  return res;
}

void precomp() {
  fact[0] = 1;
  REP(i,1, MAX_N+1) {
    fact[i] = fact[i-1] * i % MOD;
  }
}


void solve(int tt){
  ll n; cin >> n;
  ll term = n * (n - 1) % MOD;
  // term = term * 3 % MOD;
  // term = term * fpow(4, MOD - 2, MOD) % MOD;
  cout << (fact[n] * term) % MOD << endl;
  // ll num1 = ((n*(n-1))/2) % MOD;
  // ll num2 = ((n*n)/2) % MOD;
  // cout << (fact[n]%MOD * (num1%MOD) + fact[n]%MOD * num2%MOD) % MOD << endl;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    precomp();
    
    if (TESTCASES) {
        int tt; cin >> tt;
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
