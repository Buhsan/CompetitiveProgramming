#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  multiset<int> ms;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ms.insert(a);
  }

  for (int i = 0; i < m; i++) {
    int a; cin >> a;
    // auto lower = ms.lower_bound(a);
    // if (lower != ms.end() && *lower== a) {
    //   cout << a << '\n';
    //   ms.erase(lower);
    // } else if (lower != ms.begin()) {
    //   --lower;
    //   cout << *lower << '\n';
    //   ms.erase(lower);
    // } else {
    //   cout << "-1\n";
    // }
    auto upper = ms.upper_bound(a);
    if (upper == ms.begin()) {
      cout << "-1" << '\n';
    } else {
      --upper;
      cout << *upper << '\n';
      ms.erase(upper);
    }
  }

  return 0;
}
