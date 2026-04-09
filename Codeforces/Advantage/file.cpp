#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      maxi = max(maxi, v[i]);
    }
    vector<int> temp(v.begin(), v.end());
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
      if (v[i] == maxi) {
        cout << temp[n-1] - temp[n-2] << " ";
      } else {
        cout << v[i] - maxi << " ";
      }

    }
    cout << '\n';
  }

  return 0;
}
