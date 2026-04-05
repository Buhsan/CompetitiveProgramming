#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int start = 0;
    int res = 0;
    unordered_map<int, int> lastPos;

    for (int end = 0; end < n; end++) {
      int num; cin >> num;
      if (lastPos.count(num) && lastPos[num] >= start && lastPos[num] <= end) {
        start = lastPos[num]+1;
        lastPos[num] = end;
      } else if (!lastPos.count(num)) {
        lastPos[num] = end;
      }
      res = max(res, end-start+1);
    }
    cout << res << '\n';
  }
}
