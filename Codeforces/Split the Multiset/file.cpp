#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int k; cin >> k;
    int res = 0;
    if (n == 1) res = 0;
    else if (n < k) res = 1;
    else if (k == 2) res = n-1;
    else {
      res = n / (k-1) + (n % (k-1) > 1 ? 1 : 0);
    }

    cout << res << '\n';
    
  }

  return 0;
}
