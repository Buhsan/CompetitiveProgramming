#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      s.insert(v[i]);
    }
    if (s.size() == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      if (n == 2) {
        cout << v[0] << " " << v[1] << '\n';
        continue;
      }
      sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
      swap(v[1], v[v.size()-1]);
      for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
      }
      cout << '\n';
    }
  }

  return 0;
}
