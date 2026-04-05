#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;

  while (t--) {
    int n; cin >> n;
    int pr = -1;
    int cntOnes = 0, cntZeros = 0;
    //cout << "seq: ";
    for (int i = 0; i < n; i++) {
      char c; cin >> c;
      int a = c - '0';
      if (a==1) {
        cntOnes++;
        //cout << a << " ";
      } else if (pr != 0 && a == 0) {
        cntZeros++;
        //cout << a << " ";
      }
      pr = a;
    }
    //cout << endl;

    //cout << "ones: " << cntOnes << " zeros: " << cntZeros << endl;
    cout << (cntOnes > cntZeros ? "YES" : "NO") << '\n';
    //cout << endl;
  }



  return 0;
}
