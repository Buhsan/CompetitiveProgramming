#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while(cin>> n && n) {
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int result = 0;
    int curr = 0;
    vector<int> cntPos(n);
    for (int i = 1; i < n; i++) {
      result = max(result, ++cntPos[curr]);
      result = max(result, ++cntPos[i]);
      if (a[i] > a[curr]) {
        curr = i;
      }
    }

    cout << result << '\n';
  }
}
