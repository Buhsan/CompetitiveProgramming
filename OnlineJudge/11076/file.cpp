#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<ll> fact(13), p10(13);
  fact[0] = 1;
  p10[0] = 1;

  for (ll i = 1; i <= 12; i++) {
    fact[i] = i * fact[i - 1];
    p10[i] = 10 * p10[i - 1];
  }

  ll n;
  while (cin >> n && n) {
    ll sum = 0;
    unordered_map<ll, ll> freq;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;

      freq[x]++;
      sum += x;
    }

    ll d = fact[n];
    for (const pair<ll, ll> &f : freq) {
      d /= fact[f.second];
    }

    d *= sum;
    d /= n;

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
      ans += d * p10[i];
    }

    cout << ans << "\n";
  }

  return 0;
}
