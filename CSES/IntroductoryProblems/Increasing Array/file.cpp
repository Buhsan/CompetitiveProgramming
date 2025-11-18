#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a; cin >> a;
  
  long long res = 0;

  for (int i = 1; i < n; i++) {
    int b; cin >> b;
    if (b < a) {
      res += abs(a-b);
      a = b + abs(a-b);
    }
    else {
      a = b;
    }
  }
  cout << res << '\n';

  return 0;
}
