#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, m;
  while (cin >> n >> m) {
    int low = 1;
    int high = m;
    int X;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      cout << "? " << mid << " " << n << endl;
      bool good;
      cin >> good;
      if (!good) {
        low = mid + 1;
      } else {
        high = mid - 1;
        X = mid;
      }
    }
    low = 1;
    high = n;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      cout << "? " << X << " " << mid << endl;
      bool good;
      cin >> good;
      if (!good) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    int Y = low;

    cout << "=> " << X << " " << Y << endl;
  }

  return 0;
}
