#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool jolly(const vector<ll> &v) {
  int n = v.size();
  vector<bool> check(n-1);
  for (int i = 1; i < n; i++) {
    int idx = abs(v[i] - v[i-1])-1;
    if (idx >= 0 && idx < n-1) {
      check[idx] = true;
    }
  }
  for (int i = 0; i < check.size(); i++) {
    if (!check[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (jolly(a) ? "Jolly" : "Not jolly") << '\n';
  }
  return 0;
}
