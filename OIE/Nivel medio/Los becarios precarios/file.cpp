#include <bits/stdc++.h>

using namespace std;
int n;

void solve(int steps, int &res) {
  int p; cin >> p;
  if (p == 0) {
    res += (steps >= n);
  } else {
    for (int i = 0; i < p; i++) {
      solve(steps+1,res);
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(cin >> n) {
    int res = 0;
    solve(0, res);
    cout << res << '\n';
  }
  return 0;
}
