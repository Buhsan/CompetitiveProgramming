#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  while (cin >> n) {
    ll num = sqrt(n);
    cout << (num * num == n ? "ENCENDIDA" : "APAGADA") << endl;
  }

  return 0;
}
