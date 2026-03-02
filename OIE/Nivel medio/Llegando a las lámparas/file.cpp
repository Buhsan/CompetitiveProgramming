#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, n;
  while (cin >> h >> n && (h && n)) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll res = LLONG_MAX;

    int start = 0;
    int end = n-1;

    while (start < end) {
      ll num = v[start] + v[end];

      if (num >= h) {
        res = min(res, num);
        end--;
      } else {
        start ++;
      }
    }

    cout << (res == LLONG_MAX ? 0 : res) << '\n';
  }

  return 0;
}
