#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, m;
  while (cin >> n >> m && (n || m)) {
    int low = 1;
    int high = n;
    int X;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      cout << "? " << mid << " " << m << endl;
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
    high = m;
    int Y;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      cout << "? " << n << " " << mid << endl;
      bool good;
      cin >> good;
      if (!good) {
        low = mid + 1;
      } else {
        high = mid - 1;
        Y = mid;
      }
    }


    cout << "=> " << X << " " << Y << endl;
  }

  return 0;
}
