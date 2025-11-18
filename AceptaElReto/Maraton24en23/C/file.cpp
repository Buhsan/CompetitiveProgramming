#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> target(n);

    for (int i = 0; i < n; ++i) {
      cin >> target[i];
    }

    stack<int> estacion;
    int j = 0;

    for (int i = 1; i <= n; i++) {
      estacion.push(i);
      while (!estacion.empty() && estacion.top() == target[j]) {
        estacion.pop();
        ++j;
      }
    }

    cout << (j == n ? "SI" : "NO") << '\n';
  }
  return 0;
}
