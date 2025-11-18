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

const ll MOD = 998244353;

const int MAXN = 1e6+1;

vector<ll> fac(MAXN + 1), inv(MAXN + 1);

// long long inverse(const long long& x) { // x ^ -1 based on Euclidean division
//     return x <= 1 ? x : MOD - (MOD / x) * inverse(MOD % x) % MOD;
// }

ll mod_exp(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res%MOD;
}

void precompute(ll n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    // inv[n] = inverse(fac[n]);
    inv[n] = mod_exp(fac[n], MOD-2, MOD);

    for (int i = n - 1; i >= 0; --i) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }

    inv[0] = 1;
}


#define TESTCASES 0

void solve(int tt){
  ll n; cin >> n;
  ll res = n * fac[n] % MOD;
  ll init = n * fac[n] % MOD;
  ll resta = 0;

  for (int i = 1; i <= n - 1; i++) {
    // res = (res - (fac[n] * inv[i]) % MOD + MOD) % MOD;
    resta = (resta + (fac[n] * inv[i]) % MOD) % MOD;
  }
  // P(res%MOD);
  // P((init-resta+MOD)%MOD);

  // cout << max(res % MOD, (init - resta + MOD) % MOD) << endl;
  cout << ((init-resta)+MOD)%MOD << endl; 

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  precompute(MAXN);
    
    if (TESTCASES) {
        int tt; cin >> tt;
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
