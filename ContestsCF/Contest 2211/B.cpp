#include <bits/stdc++.h>

using namespace std;


int isPrime(int n) {
  if (n <= 1) return  1;

  int res = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n%i == 0) {
      if (n / i == i) {
        res++;
      } else {
        res+=2;
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    /*int res = 1;
    if (n == 0 && m) {
      res = isPrime(m);
    } else if (m == 0 && n) {
      res = isPrime(n);
    } else if (abs(n-m) == 2) {
      res = 2;
    }*/
    cout << isPrime(abs(n-m)) << '\n';
    for (int i = 0; i < n; i++) {
      cout << 1 << " ";
    }
    for (int i = 0; i < m; i++) {
      cout << -1 << " ";
    }
    cout << '\n';
  }

  return 0;
}
