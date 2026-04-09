#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<ll> sufixZeros(n);
    ll cntZeros = 0;
    for (ll i = n - 1; i >= 0; i--) {
      cntZeros += a[i] == 0;
      sufixZeros[i] = cntZeros;
    }
    vector<ll> prefOnes(n);
    ll cntOnes = 0;
    for (ll i = 0; i < n; i++) {
      cntOnes += a[i] == 1;
      prefOnes[i] = cntOnes;
    }

    ll normalInv = 0;
    for (ll i = 0; i < n; i++) {
      if (a[i] == 1) normalInv += sufixZeros[i];
    }

    ll ans = normalInv;

    for (ll i = 0; i < n; i++) {
      ll newInv = normalInv;

      if (a[i] == 0) {
        // De 0 a 1
        newInv += i + 1 < n ? sufixZeros[i + 1] : 0;
        newInv -= prefOnes[i];
      } else {
        // De 1 a 0
        newInv += i - 1 >= 0 ? prefOnes[i - 1] : 0;
        newInv -= sufixZeros[i];
      }

      ans = max(ans, newInv);
    }
    cout << ans << "\n";
  }
  return 0;
}
