#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k && (n || k)) {
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
      ll num;
      cin >> num;
      sum += num;

      if (pq.size() < k) {
        pq.push(num);
      } else if (num > pq.top()) {
        pq.pop();
        pq.push(num);
      }
    }
    ll richest = 0;
    while (!pq.empty()) {
      richest += pq.top();
      pq.pop();
    }

    cout << sum << " " << richest << '\n';
  }
  return 0;
}
