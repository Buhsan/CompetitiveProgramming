#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  int maxi = 1;
  int res = 1;

  for (int i=1; i < n; i++) {
    if (s[i] == s[i-1]) {
      maxi++;
    } else {maxi = 1;}
    res = max(maxi, res);
  }
  cout << res << '\n';

  return 0;
}
