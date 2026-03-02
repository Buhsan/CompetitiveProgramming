#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int left, right;
  while (cin >> left >> right) {
    int res = 0;
    int cnt = 1;
    int i = min(left, right);
    int j = max (left, right);
    while (i <= j) {
      int n = i;
      while (n != 1) {
        if (n%2 == 0) n/=2;
        else n = (3 * n) + 1;
        cnt++;
        if (n == 1) break;
      }
      res = max(res, cnt);
      cnt = 1;
      i++;
    }
    cout << left << " " << right << " " << res << '\n';
  }
}
