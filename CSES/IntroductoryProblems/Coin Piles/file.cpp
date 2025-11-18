#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long t; cin >> t;
  while(t--) {
    long long a, b; cin >> a >> b;
    int y = (2*a - b)/3;
    int x = a - 2 * y;

    bool ans = ((a-x-2*y == 0) && (b - y - 2*x == 0) && (x >= 0 && y >= 0));
    cout << (ans ? "YES" : "NO") << '\n';
  }
  return 0;
}
