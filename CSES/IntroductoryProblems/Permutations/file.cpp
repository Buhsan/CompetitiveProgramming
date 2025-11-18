#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
  }
  else if (n == 4) {
    cout << "2 4 1 3" << '\n';
  }
  else if (n < 4 && n > 1) {
    cout << "NO SOLUTION" << '\n';
  } else {
    for (int i = 1; i <= n;) {
      cout << i << " ";
      i+=2;
    }
    for (int i = 2; i <= n;) {
      cout << i << " ";
      i+=2;
    }
    cout << '\n';
  }


  return 0;
}
