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

const int MAX_N = 1e6;

vector<ll> fact(MAX_N + 1), inv_fact(MAX_N + 1);

ll mod_exp(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute(ll n) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[n] = mod_exp(fact[n], MOD - 2, MOD);

    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }

    inv_fact[0] = 1;
}

ll bincof(ll n, ll k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}


#define TESTCASES 0

void solve(int tt){
  string s; cin >> s;
  ll n = s.size();
  precompute(n);
  map<char, int> freq;
  REP(i,0,n){
    freq[s[i]]++;
  }
  vector<int> repetions;
  REPLIST(i,freq) {
    repetions.push_back(i.second);
  }
  SORTDECR(repetions);
  ll res = 1;
  REP(i,0,repetions.size()) {
    res = (bincof(n,repetions[i]) * res)%MOD;
    n-=repetions[i];
  }
  cout << res << endl;
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
