#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p;
  while (cin >> n >> p && (n || p)) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int start = 0;
    int end = n-1;
    ll res = 0;
    while (start < end) {
      ll num = v[start] + v[end];
      if (num > p) {
        end--;
      } else {
        res += (end-start);
        start++;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
