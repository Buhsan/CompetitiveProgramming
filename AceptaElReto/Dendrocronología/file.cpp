#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  int n;
  while (cin >> n) {
    ll layer = ceil(n / 2.0);
    vector<ll> res(layer);
    ll a, num;
    for (int i = 0; i < layer; i++) {
      num = n - 2 * (i + 1);
      num = (num < 0 ? 0 : num);
      for (int j = 0; j <= i; j++) {
        cin >> a;
        res[j] += a;
      }

      for (int j = 0; j < num; j++) {
        cin >> a;
        res[i] += a;
      }

      if (i == layer - 1 && n%2) {
        for (int j = i-1; j >= 0; j--) {
          cin >> a;
          res[j] += a;
        }
      } else {
        for (int j = i; j >= 0; j--) {
          cin >> a;
          res[j] += a;
        }
      }

    }

    if (n % 2 == 0) {
      for (int j = 0; j < layer; j++) {
        cin >> a;
        res[j] += a;
      }
      for (int j = 0; j < num; j++) {
        cin >> a;
        res[layer - 1] += a;
      }
      for (int j = layer - 1; j >= 0; j--) {
        cin >> a;
        res[j] += a;
      }
    }

    for (int i = layer - 2; i >= 0; i--) {
      num = n - 2 * (i + 1);
      num = (num < 0 ? 0 : num);
      for (int j = 0; j <= i; j++) {
        cin >> a;
        res[j] += a;
      }

      for (int j = 0; j < num; j++) {
        cin >> a;
        res[i] += a;
      }

      if (i == layer - 1 && n%2) {
        for (int j = i-1; j >= 0; j--) {
          cin >> a;
          res[j] += a;
        }
      } else {
        for (int j = i; j >= 0; j--) {
          cin >> a;
          res[j] += a;
        }
      }

    }

    for (int i = layer - 1; i >= 0; i--) {
      cout << res[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";
  }
}
