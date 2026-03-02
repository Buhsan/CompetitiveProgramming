#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  vector<ll> input(n);
  input[0] = x;
  for (int i = 1; i < n; i++) {
    input[i] = (input[i - 1] * a + b) % c;
  }
  ll res = -1;
  int start = 0;
  int end = 0;
  ll sum = 0;
  while (end < n) {
    sum += input[end];
    if (end - start + 1 == k) {
      res = (res == -1 ? sum : res ^ sum);
      sum -= input[start];
      start++;
    }
    end++;
  }

  cout << res << '\n';

  return 0;
}
