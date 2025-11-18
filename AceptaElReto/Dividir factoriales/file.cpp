#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll calc(ll start, ll end) {
  ll res = 1;
  for (ll i = start; i >= end; i--) {
    res *= i;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b && a >= b) {
    ll result = 0;
    if (a == b)
      result = 1;
    else {
      result = calc(a, b + 1);
    }

    cout << result << endl;
  }

  return 0;
}
