#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int n, k;
  while (cin >> n >> k && n) {
    multiset<int> ms;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int nextToDelete = 0;
    for (int i = 0; i < n; i++) {
      ms.insert(v[i]);
      if (ms.size() == k) {
        cout << *prev(ms.end()) << ' ';
        ms.erase(ms.find(v[nextToDelete]));
        nextToDelete++;
      }
    }
    cout << '\n';
  }

  return 0;
}
