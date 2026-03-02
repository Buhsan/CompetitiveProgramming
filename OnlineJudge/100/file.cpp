#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int left, right;
  unordered_map<int,int> sol;
  while (cin >> left >> right) {
    int res = 0;
    int l = min(left, right);
    int r = max(left, right);
    for (int i = l; i <= r; i++) {
      if (sol.count(i)) {
        res = max(res, sol[i]);
        continue;
      }
      int n = i;
      int cnt = 0;
      sol[1] = 1;
      sol[2] = 2;
      // cout << n << ": ";
      // cout << n;
      while (n != 1) {
        cnt++;
        if (sol.count(n)) {
          cnt += sol[n] - 1;
          break;
        }
        if (n%2){
          n = n*3 + 1;
        } else {
          n/=2;
        }
        // cout << " " << n;
      }
      sol[i] = cnt;
      // cout << " (" << cnt << ") "<< endl;
      res = max(res, cnt);
    }
    cout << left << ' ' << right << ' ' << res << '\n';

    // for (auto p : sol) {
    //   cout << p.first << " " << p.second << endl;
    // }
  }
  return 0;
}
