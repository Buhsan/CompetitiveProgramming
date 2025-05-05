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

using u64 = long long;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
 
 
bool MillerRabin(u64 n) {
    if (n < 2)
        return false;
 
    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }
 
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}


u64 mult(u64 a, u64 b, u64 mod) {
    return u64((u128)a * b % mod);
}

u64 f(u64 x, u64 c, u64 mod) {
    return (mult(x, x, mod) + c) % mod;
}

u64 abs (u64 x, u64 y) {
  return (x > y ? x-y : y-x);
}

u64 min (u64 x, u64 y) {
  return (x > y ? y : x);
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
u64 brent (u64 n, u64 x0=2, u64 c0=1) {
  u64 x = rng() % (n - 1) + 1;
  u64 c = rng() % (n - 1) + 1;
  u64 g = 1;
  u64 q = 1;
  u64 xs, y;

  int m = 128;
  ll l = 1;
  while (g == 1) {
    y = x;
    for (ll i = 1; i < l; i++) {
      x = f(x, c, n);
    }
    ll k = 0;
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




void factorize(u64 n, map<u64, int> &factors) {
  if (n == 1) return;
  bool res = MillerRabin(n);
  if (res) {
    factors[n]++;
    return;
  }

  else {
    u64 divisor = brent(n);
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
  u64 n;
  while (cin >> n && n) { 
    map<u64, int> factors;
    factorize(n, factors);
    cout << n << ": ";
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





// u64 brent(u64 n) {
//     if (n % 2 == 0) return 2;
//     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//     u64 y = rng() % (n - 1) + 1;
//     u64 c = rng() % (n - 1) + 1;
//     u64 m = 128;
//     u64 g = 1, r = 1, q = 1;
//     u64 x, ys;
//
//     while (g == 1) {
//         x = y;
//         for (u64 i = 0; i < r; ++i)
//             y = f(y, c, n);
//
//         u64 k = 0;
//         while (k < r && g == 1) {
//             ys = y;
//             u64 limit = min(m, r - k);
//             for (u64 i = 0; i < limit; ++i) {
//                 y = f(y, c, n);
//                 q = mult(q, (x > y ? x - y : y - x), n);
//             }
//             g = __gcd(q, n);
//             if (g == n || q == 0) { 
//                 do {
//                     ys = f(ys, c, n);
//                     g = __gcd((x > ys ? x - ys : ys - x), n);
//                 } while (g == 1);
//                 return g;
//             }
//             k += m;
//         }
//         r <<= 1; 
//     }
//     return g;
// }


// long long mulmod(long long a, long long b, long long mod) {
//     long long result = 0;
//     a %= mod;
//     while (b > 0) {
//         if (b & 1)
//             result = (result + a) % mod;
//         a = (2 * a) % mod;
//         b >>= 1;
//     }
//     return result;
// }
//
// long long power(long long a, long long b, long long mod) {
//     long long result = 1;
//     a %= mod;
//     while (b > 0) {
//         if (b & 1)
//             result = mulmod(result, a, mod);
//         a = mulmod(a, a, mod);
//         b >>= 1;
//     }
//     return result;
// }
//
// long long pollards_rho(long long n) {
//     if (n % 2 == 0) return 2;
//     long long x = rand() % (n - 2) + 2;
//     long long y = x;
//     long long c = rand() % (n - 1) + 1;
//     long long d = 1;
//     long long size = 2;
//     long long count = 0;
//     
//     while (d == 1) {
//         count++;
//         x = (mulmod(x, x, n) + c) % n;
//         d = __gcd(abs(x - y), n);
//         if (count == size) {
//             y = x;
//             size *= 2;
//             count = 0;
//         }
//     }
//     if (d == n)
//         return pollards_rho(n); // Retry
//     return d;
// }
