#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    vector<int> cntPos(n);
    int curr = 0;
    for (int i = 1; i < n; i++) {
      cntPos[curr]++;
      cntPos[i]++;

      if (a[i] > a[curr]) {
        curr = i;
      }
    }
    cout << *max_element(cntPos.begin(), cntPos.end()) << endl;
  }
  return 0;
}
