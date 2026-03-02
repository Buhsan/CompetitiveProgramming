#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> calories(n), vitamins(n);

    for (int i = 0; i < n; i++) cin >> calories[i];
    for (int i = 0; i < n; i++) cin >> vitamins[i];

    int limitCalories; cin >> limitCalories;

    ll sumC = 0, sumV = 0;
    int start = 0;
    ll res = 0;
    for (int end = 0; end < n; end++) {
      sumC+=calories[end];
      sumV+=vitamins[end];
      while (start <= end && sumC > limitCalories) {
        sumC-=calories[start];
        sumV-=vitamins[start];
        start++;
      }
      res = max(res,sumV);
    }
    cout << res << '\n';
  }
  return 0;
}
