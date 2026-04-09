#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      int curr;
      cin >> curr;
      if (curr != prev) a.push_back(curr);
      prev = curr;
    }

    n = a.size();

    if (n == 1) {
      cout << "YES\n";
      continue;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cnt += (a[i] < a[i + 1]);
      } else if (i == n - 1) {
        cnt += (a[i] < a[i - 1]);
      } else {
        cnt += (a[i] < a[i - 1] && a[i] < a[i + 1]);
      }
    }

    cout << (cnt == 1 ? "YES" : "NO") << "\n";
  }
  return 0;
}
