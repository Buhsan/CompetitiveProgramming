#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    bool res = true;

    for (int i = 0; i < n; i++) {
      bool mid = (i >= n-k && i < k);
      if (!mid) {
        if (b[i] != -1 && b[i] != a[i]) {
          cout << "NO" << '\n';
          res = false;
          break;
        }
      } 
    }
    if (!res) continue;

    if (n < 2*k) {
      set<int> aVal;
      set<int> bVal;


      for (int i = n-k; i < k; i++) {
        aVal.insert(a[i]);
      }

      for (int i = n-k; i < k; i++) {
        if (b[i] != -1) {
          if (!aVal.count(b[i]) || bVal.count(b[i])){
            cout << "NO" << endl;
            res = false;
            break;
          }
        }
        bVal.insert(b[i]);
      }
    }
    if (!res) continue;
    cout << "YES" << endl;
  }

  return 0;
}
