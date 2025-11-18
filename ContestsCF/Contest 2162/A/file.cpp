#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      maxi = max(a, maxi);
    }
    cout << maxi << "\n";
  }


  return 0;
}
