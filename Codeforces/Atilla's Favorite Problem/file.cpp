#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
      char c; cin >> c;
      res = max(res, c - 'a');
    }
    cout << res+1<< '\n';
  }


  return 0;
}

