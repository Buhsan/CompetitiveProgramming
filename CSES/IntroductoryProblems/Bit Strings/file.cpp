#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

typedef long long ll;


ll modExp(ll base, ll exp, ll mod) {
  ll result = 1;
  base %= mod;

  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;

    base = (base * base) % mod;
    exp /= 2;
  }

  return result;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  cout << modExp(2, n, MOD) << '\n';
  return 0;
}
