#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int,int> freq;
    bool res = 0;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      freq[a]++;
      if (freq[a] > 1) res = true;
    }


    cout << (res ? "YES" : "NO") << '\n';

  }



  return 0;
}
