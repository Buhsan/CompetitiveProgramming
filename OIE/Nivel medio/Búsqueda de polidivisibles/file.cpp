#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll i, ll &curr, const ll &d) {
  cout << curr << "\n";

  if (i == d) return;

  for (ll x = 0; x <= 9; x++) {
    curr *= 10;
    curr += x;

    if (curr % (i + 1) == 0) {
      solve(i + 1, curr, d);
    }
    curr /= 10;
  }
}

int main() {
  ll n, d;
  while (cin >> n >> d) {
    ll curr = n;

    ll aux = n;
    ll currDig = 0;
    while (aux) {
      aux /= 10;
      currDig++;
    }

    solve(currDig, curr, d);
    cout << "---\n";
  }
  return 0;
}
