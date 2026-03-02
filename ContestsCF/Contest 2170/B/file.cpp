#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int length = 0;
    int sum = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      cout << a <<  " ";
      sum+=a;
      maxi = max(maxi, a);
      if (a) length++;
    }
    cout << '\n';
    int res = 0;
    if (abs(sum-n)) res = min(length, max(length, abs(sum-n)));
    else res = 1;
    cout << res << '\n';
  }
  return 0;
}
