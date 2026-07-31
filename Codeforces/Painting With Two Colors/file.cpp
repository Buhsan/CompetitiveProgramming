#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    int diffA = n - a;
    int diffB = n - b;
    bool res = (diffA%2 == 0 && diffB%2 == 0) || (diffA%2 == 1 && diffB%2 == 0 && diffB < diffA);
    cout << (res ? "YES" : "NO") << '\n';
  }

  return 0;
}
