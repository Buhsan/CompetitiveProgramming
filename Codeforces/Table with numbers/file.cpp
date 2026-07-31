#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio();
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, h, l;
    cin >> n >> h >> l;
    int res = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort (v.begin(), v.end());
    int low = 0;
    int high = n-1;
    while (low < high) {
      if ((v[low] <= l && v[high] <= h) || (v[low] <= h && v[high] <= l)) {
        low++;
        high--;
        res++;
      } else {
        high--;
      }
    }
    cout << res << '\n';
  }


  return 0;
}
