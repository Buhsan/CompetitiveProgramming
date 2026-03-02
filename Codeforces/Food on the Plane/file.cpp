#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string ns;
  cin >> ns;

  string nsAux = ns.substr(0, ns.size() - 1);
  ll I = stoll(nsAux) - 1;
  char s = ns.back();

  ll J = 5 - (s - 'a');

  // for (int i = 0; i < 20; i++) {
  //   int first = (i % 2) * 7 + (i / 4) * 16 + 1;
  //
  //   for (int j = 0; j < 6; j++) {
  //     int val = 0;
  //     if (j == 0) val = 0;
  //     if (j == 1) val = 1;
  //     if (j == 2) val = 2;
  //     if (j == 5) val = 3;
  //     if (j == 4) val = 4;
  //     if (j == 3) val = 5;
  //     ll ans = first + val;
  //     cout << ans << " ";
  //   }
  //   cout << "\n";
  // }

  ll first = (I % 2) * 7 + (I / 4) * 16 + 1;

  ll val = 0;
  if (J == 0) val = 0;
  if (J == 1) val = 1;
  if (J == 2) val = 2;
  if (J == 5) val = 3;
  if (J == 4) val = 4;
  if (J == 3) val = 5;
  ll ans = first + val;

  cout << ans << "\n";

  return 0;
}
