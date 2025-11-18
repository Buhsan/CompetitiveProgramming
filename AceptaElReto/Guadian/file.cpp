#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int act = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (!act) {
        res++;
        act = v[i];
      } else {
        // act = min(--act, v[i]);
        act = min(act - 1, v[i]);
      }
      cout << "act: " << act << " en pila " << res << '\n';

    }

    cout << res << endl;
  }
  return 0;
}
