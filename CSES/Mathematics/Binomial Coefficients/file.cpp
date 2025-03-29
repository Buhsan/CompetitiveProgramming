// // ll bincof(ll n, ll r) {
// //     if (r > n) return 0;
// //     if (r == 0 || r == n) return 1;

// //     ll res = 1;
// //     for (ll i = 0; i < r; ++i) {
// //         res *= ((n - i)%MOD);
// //         res /= ((i + 1)%MOD);
// //     }
// //     return res%MOD;
// // }

// // vector<vector<ll>> dp(1e5 + 1, vector<ll> (1e5 + 1, 0));
// // int binomialCoeff(ll n, ll k) {
// //   if (dp[n][k]%MOD != 0) return dp[n][k]%MOD;
// //   for (ll i = 0; i <= n; i++) {
// //     for (ll j = 0; j <= min(i, k); j++) {
// //       if (j == 0 || j == i)
// //         dp[i][j] = 1;
// //       else
// //         dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
// //     }
// //   }
// //   return dp[n][k]%MOD;
// // }

// // ll bincof_dp(ll n, ll k) {
// //     if (k > n) return 0;
// //     if (k == 0 || k == n) return 1;
// //     if (dp[n][k] != -1) return dp[n][k];
// //     ll a = bincof_dp(n - 1, k - 1);
// //     ll b = bincof_dp(n - 1, k);
// //     return dp[n][k] = a + b;
// // }
// vector<ll> dp(1e6 + 1);
// void precompute(ll n) {
//   dp[0] = 1;
//   for (ll i = 1; i <= n; ++i) {
//     for (ll j = i; j > 0; --j) {
//       dp[j] = (dp[j] + dp[j - 1]) % MOD;
//     }
//   }
// }

// // ll bincof(ll n, ll k) {
// //   dp[0] = 1;
// //   for (ll i = 1; i <= n; i++) {
// //     for (ll j = min(i, k); j > 0; j--)
// //       dp[j] = (dp[j] + dp[j - 1])%MOD;
// //   }
// //   return dp[k]%MOD;
// // }


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    inv_fact[MAX_N] = mod_exp(fact[MAX_N], MOD - 2, MOD);

    for (int i = MAX_N - 1; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }

    inv_fact[0] = 1;
}

ll bincof(ll n, ll k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

void solve(int tt) {
    ll a, b;
    cin >> a >> b;
    cout << bincof(a, b) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int tt;
    cin >> tt;
    while (tt--) {
        solve(tt);
    }

    return 0;
}
