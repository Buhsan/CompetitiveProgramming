#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long res = 0;
  int n; cin >> n;
  n/=5;

  while(n>0) {
    res+=n;
    n/=5;
  }
  cout << res << '\n';


  return 0;
}
