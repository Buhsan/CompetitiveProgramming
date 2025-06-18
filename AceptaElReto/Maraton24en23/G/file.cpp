#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) {
      break;
    }
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
      ll aux;
      cin >> aux;
      sum += aux;

      if (pq.size() < k) {
        pq.push(aux);
      } else if (aux > pq.top()) {
        pq.pop();
        pq.push(aux);
      }
    }
    ll richest = 0;
    while (!pq.empty()) {
      richest += pq.top();
      pq.pop();
    }

    cout << sum << " " << richest << endl;
  }
  return 0;
}
