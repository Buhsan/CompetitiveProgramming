#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    unordered_map<int, pair<int,int>> pos;
    int prev = -1;
    int ini = 1;
    int fin = 1;
    while (n--) {
      int a; cin >> a;
      if (prev == -1) prev = a;

      if (prev != a) {
        pos[prev] = {ini, fin-1};
        ini = fin;
      }

      fin++;
      prev = a;
    }
    pos[prev] = {ini, fin-1};
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
      int c; cin >> c;
      if (pos.count(c)) {
        cout << pos[c].first <<  " " << pos[c].second << '\n';
      } else {
        cout << "NO HAY\n";
      }
    }
    cout << "---\n";
  }

  return 0;
}
