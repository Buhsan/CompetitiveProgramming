#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int start, n;
  while (cin >> start >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll res = 0;

    int left = 0;
    int right = n-1;
    ll val = start;

    while (left <= right) {
      res+= ((ll)(v[left] * val)) % 78787;
      if (left==right) break;
      res+= ((ll)(v[right] * val)) % 78787;

      left++;
      right--;
      val = (val * 3) % 78787;
    }



    cout << (res % 78787) << '\n';

  }
  return 0;
}
