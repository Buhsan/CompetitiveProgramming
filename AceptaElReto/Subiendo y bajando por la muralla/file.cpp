#include <bits/stdc++.h> 

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int mini = 0;
    int maxi = -1;
    int curr = 0;
    int res = 0;

    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      curr += a;
      res = max(res, curr-mini);

      if (curr < mini) {
        mini = curr;
      }
    }


    cout << res << '\n';
  }


  return 0;
}
