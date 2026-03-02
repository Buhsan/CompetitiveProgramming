#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll extractFirstDigits(ll e, ll n) {
  return pow(2, e - log2(10) * floor(e * log10(2) - n + 1));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll n;
  while (cin >> n) {
    ll numDigitsN = floor(log10(n)) + 1;

    ll i = numDigitsN + 1;

    while (true) {
      // ll val = round(log2(n * pow(10, i)));
      ll val = round(log2(n) + i * log2(10));
      ll numDigitsVal = floor(val * log10(2)) + 1;

      // cout << "i = " << i << endl;
      // cout << "val = " << val << endl;
      // cout << "found = " << extractFirstDigits(val, numDigitsN) << endl;
      // if (i > 400) break;
      if (extractFirstDigits(val, numDigitsN) == n) {
        cout << val << "\n";
        break;
      }
      i++;
    }
    // cout << numDigitsN << endl;
    // ll ans = 0;

    // int i = log10(n) + 1;
    // while (true) {
    //   double val = log2(n * pow(10, i));
    //   if (abs(val - round(val)) < 0.01) {
    //   }
    //   i++;
    // }

    // cout << ans << "\n";
  }
  // ll p = 1;

  // for (ll i = 0; i < 1000; i++) {
  //   // cout << "i = " << i << endl;

  //   ll firstDigit = pow(2, i - log2(10) * floor(i * log10(2)));
  //   ll secondDigit = (ll) (pow(2, i - log2(10) * (floor(i * log10(2)) - 1))) % 10;
  //   ll thirdDigit = (ll) (pow(2, i - log2(10) * (floor(i * log10(2)) - 2))) % 10;
  //   cout << firstDigit << " " << secondDigit << " " << thirdDigit << endl;
  //   // cout << "2^" << i << " = " << p << "\n";
  //   // cout << p << " (2^" << i << ")\n";
  //   p *= 2;
  // }
  return 0;
}
