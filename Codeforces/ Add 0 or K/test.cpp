#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < n; j++) {
        cout << v[j] + (k*i) << '\t';
      }
      cout << endl;
    }
    cout << endl;
    cout << endl;
  }

  return 0;
}
