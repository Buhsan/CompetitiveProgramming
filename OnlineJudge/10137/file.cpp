#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n && n) {
    ll sum = 0;
    vector<ll> student(n);
    for (int i = 0; i < n; i++) {
      double a; cin >> a;
      student[i] = (ll)(a * 100 + 0.5);
      sum += student[i];
    }
    ll average = sum/n;
    ll extra = sum%n;

    ll give = 0;
    ll receive = 0;

    for (int i = 0; i < n; i++) {
      if (student[i] > average) {
        ll diff = student[i] - average;
        if (extra > 0) {
          receive += (diff - 1);
          extra--;
        } else {
          receive += diff;
        }
      } else {
        give += (average - student[i]);
      }
    }
    ll res = max(give, receive);
    cout << "$" << res / 100 << "." << setfill('0') << setw(2) << res % 100 << '\n';
  }
  return 0;
}
