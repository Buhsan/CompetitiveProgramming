#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end(), [](int a, int b) {return a > b;});

  vector<int> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i-1] + a[i];
  }

  int total = pref[n-1];

  for (int i = 0; i < n; i++) {
    if (pref[i] > total - pref[i]) {
      cout << i + 1 << endl;
      break;
    }

  }

  return 0;
}
