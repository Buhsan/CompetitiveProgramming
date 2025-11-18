#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __uint128_t u128;

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

using u64 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = ((result%mod) * (base% mod)) % mod;
        base = ((base%mod) * (base% mod)) % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = ((x%n) * (x%n))%n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
 
bool MillerRabin(u128 n) {
    if (n < 2)
        return false;
 
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}


// u128 mult(u128 a, u128 b, u128 mod) {
//     u128 result = 0;
//     a %= mod;
//     b %= mod;
//     while (b) {
//         if (b & 1)
//             result = (result + a) % mod;
//         a = (a + a) % mod;
//         b >>= 1;
//     }
//     return result;
// }

u128 mult(u128 a, u128 b, u128 mod) {
    return (a%mod * b % mod)%mod;
}

u128 f(u128 x, u128 c, u128 mod) {
    return (mult(x, x, mod) + c) % mod;
}

u128 abs (u128 x, u128 y) {
  return (x > y ? x-y : y-x);
}

u128 min (u128 x, u128 y) {
  return (x > y ? y : x);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

u128 brent (u128 n, u128 x0=2, u128 c0=1) {
  u64 x = rng() % (n - 1) + 1;
  u64 c = rng() % (n - 1) + 1;
  u64 g = 1;
  u64 q = 1;
  u64 xs, y;

  u128 m = 128;
  u128 l = 1;
  while (g == 1) {
    y = x;
    for (ll i = 1; i < l; i++) {
      x = f(x, c, n);
    }
    u128 k = 0;
    while (k < l && g == 1) {
      xs = x;
      u64 limit = min(m, l-k);
      for (ll i = 0; i < limit; i++) {
        x = f(x,c,n);
        q = mult(q, abs(y,x), n);
      }
      g = __gcd(q, n);
      if (g == n || q == 0) {
        do {
          xs = f(xs, c, n);
          g = __gcd(abs(xs, y), n);
        }
        while (g == 1);
        return g;
      }
      k += m;
    }
    l*=2;
  }
 return g;
}

ostream& operator<<(ostream& out, u128 n) {
    if (n == 0) {
        out << '0';
        return out;
    }
    if (n < 0) {
        out << '-';
        n = -n;
    }
    string s;
    while (n > 0) {
        s.push_back('0' + n % 10);
        n /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

istream& operator>>(istream& in, u128& n) {
    string s;
    in >> s;
    n = 0;
    bool neg = false;
    int i = 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < s.size(); ++i) {
        if (!isdigit(s[i])) break;
        n = n * 10 + (s[i] - '0');
    }
    if (neg) n = -n;
    return in;
}


void factorize(u128 n, map<u128, int> &factors) {
  if (n == 1) return;
  bool res = MillerRabin(n);
  if (res) {
    factors[n]++;
    return;
  }

  else {
    u128 divisor = brent(n);
    while (!MillerRabin(divisor)) {
      divisor = brent(divisor);
    }
    if (divisor == n) {
      factors[n]++;
      return;
    }
    factorize(divisor, factors);
    factorize(n / divisor, factors);
  }
}

void solve(int tt){
   u128 n = 1234567890123456789;
   while (cin >> n && n) { 
     map<u128, int> factors;
     factorize(n, factors);
     for (auto p : factors) {
       cout << p.first << "^" << p.second << " "; 
     }
     cout << endl;
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
