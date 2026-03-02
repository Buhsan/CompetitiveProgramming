#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m && (n && m)) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    int start = 0;
    ll sum =  0;
    ll res = 0;
    for (int end = 0; end < n; end++) {
      sum++;
      while (start < end && v[end]-v[start]+1 > m) {
        sum--;
        start++;
      }
      res = max(res,sum);
    }

    cout << res << '\n';
  }
  return 0;
}
