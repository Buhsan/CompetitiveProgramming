#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    if (x > y)  {
      cout << "NO\n";
      continue;
    }
    int even = x;
    int odd = y;
    if ((x+y) % 2) odd--;
    else even--;
    if (even < 0 || odd < 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";

    int node = 2;
    for (int i = 0; i < odd; i++) {
      cout << "1 " << node << '\n';
      node++;
    }

    int start = 2;
    for (int i = 0; i < even; i++) {
      cout << start << " " << node << '\n';
      node++, start++;
    }
  }
  
  


  return 0;
}
