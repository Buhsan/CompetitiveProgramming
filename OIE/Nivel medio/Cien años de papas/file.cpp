#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int start = 0;
    int sum = 0;
    int res = 0;
    for (int end = 0; end < n; end++) {
      sum = (v[end]-v[start]);
      while (start < end && sum > 99) {
        start++;
        sum = (v[end]-v[start]);
      }
      res = max(res, end-start+1);
    }

    cout << res << '\n';
  }

  return 0;
}
