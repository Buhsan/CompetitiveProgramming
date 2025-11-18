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



void factorize(u64 n, int &odd, int &even) {
  if (n == 1) return;
  bool res = MillerRabin(n);
  if (res) {
    if (n%2) odd++;
    if (n==2) even++;
    return;
  }
  else {
    u64 divisor = brent(n);
    while (!MillerRabin(divisor)) {
      divisor = brent(divisor);
    }
    if (divisor == n) {
      if (n%2) odd++;
      if (n==2) even++;
      return;
    }
    factorize(divisor, odd, even);
    factorize(n / divisor, odd, even);
  }
}




// void factorize(u64 n, map<u64, int> &factors) {
//   if (n == 1) return;
//   bool res = MillerRabin(n);
//   if (res) {
//     factors[n]++;
//     return;
//   }
//
//   else {
//     u64 divisor = brent(n);
//     while (!MillerRabin(divisor)) {
//       divisor = brent(divisor);
//     }
//     if (divisor == n) {
//       factors[n]++;
//       return;
//     }
//     factorize(divisor, factors);
//     factorize(n / divisor, factors);
//   }
// }
//



#define TESTCASES 1

void solve(int tt){
  int n; cin >> n;
  string one = "Ashishgup";
  string two  = "FastestFinger";
  ll res = 0;
  // cout << n << ": ";
  if (n%2) {
    if (n == 1) {
      cout << two << endl;
      return;
    }
    cout << one << endl;
    return;
  }
  else {
    if (n == 2) {
      cout << one << endl;
      return;
    }
    // int odd = 0;
    // int twos = 0;
    // factorize(n, odd, twos);
    // // cout << n << ": " << odd << " " << twos << endl;
    // if (odd == 0) {
    //   cout << two << endl;
    //   return;
    // }
    // if (twos > 1) {
    //   cout << one << endl;
    //   return;
    // }
    // cout << (odd%2 ? two : one) << endl;

    
    // P(factors.size());
    // cout << n << ": ";
    // for (auto p : factors) {
    //   cout << p.first << "^" << p.second << " "; 
    // }
    // if (factors[2] == 1) {
    //   cout << two << endl;
    // }
    // else if (factors.size() == 1 && factors[2] > 1) {
    //   cout << two << endl;
    // }
    // else {
    //   cout << one << endl;
    // }
    for (int i = 3; i*i <= n; i++) {
      if (n%i == 0) {
        if (i%2 || n/i%2) {
          cout << (n/i == 2 ? two : one) << endl;
          return;
        }
      }
    }
    cout << two << endl;
    // cout << (factors[2] == 1 || (factors.size() == 1 && factors[2] > 1) ? two : one) << endl;
    
    // REPV(i, n/2, 0) {
    //   if (i%2 && n%i == 0) {
    //     P(n);
    //     P(i);
    //     P(n/i);
    //     cout << ((n/i == 2 || i == 1) ? two : one) << endl;
    //     return;
    //   }
    // }
    // factorize(n, res);
    // P(n);
    // P(res);
    // cout << (res==1 ? two: one) << endl;
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
