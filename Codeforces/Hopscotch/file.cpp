#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, x, y; cin >> a >> x >> y;

  int res = 0;
  int h = y;
  h-=a;
  int level = (y < a && y != 0) ? level = 0 : h/a + 1;
  if (y%a == 0 || (level%2 == 0 && (x <= -a || x >= a)) || ((level%2 || level == 0) && (x <= -a/2.0 || x >= a/2.0)) || ((level != 0 &&level%2 == 0) && x == 0)) {
    res = -1;
  }
  else if (!level){
    res = 1;
  }
  else {
    res = level%2 ? level + level/2+1 : level + level/2 + (x > 0);
  }

  cout << res << '\n';

  return 0;
}
