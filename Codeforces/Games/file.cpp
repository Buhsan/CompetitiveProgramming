#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> guest(101,0), host(101,0);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int h, g; cin >> h >> g;
    if (guest[h]) cnt+=guest[h];
    if (host[g]) cnt+=host[g];
    host[h]++;
    guest[g]++;
  }

  cout << cnt << '\n';
  return 0;
}
