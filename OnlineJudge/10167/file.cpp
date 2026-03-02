#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<pair<int,int>> cherries;
    for (int i = 0; i < 2*n; i++) {
      int a, b; cin >> a >> b;
      cherries.push_back({a,b});
    }

    int right = 0, left = 0, on = 0;
    int a, b = 0;
    for (a = -500; a <= 500; a++) {
      for (b = -500; b <= 500; b++) {
        right = 0, left = 0, on = 0;
        for (int i = 0; i < 2*n; i++) {
          int d = a*cherries[i].first + b*cherries[i].second;
          if (d > 0) right ++;
          else if (d < 0) left++;
          else if (d == 0) on++;
        }
        if (right == left && !on) break;
      }
      if (right == left && !on) break;
    }
    cout << a << " " << b << '\n'; 

  }
  return 0;
}
