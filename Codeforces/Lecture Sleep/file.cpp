#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n), t(n);
  for (int i = 0; i < n; i++) cin>>a[i];
  for (int i = 0; i < n; i++) cin>>t[i];
  
  long long base = 0;
  vector<long long> asleep(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (t[i]) base += a[i];
    asleep[i + 1] = asleep[i] + (t[i] ? 0 : a[i]);
  }
  
  long long bestExtra = 0;
  for (int i = 0; i + k <= n; i++) {
    long long extra = asleep[i+k] - asleep[i];
    bestExtra = max(bestExtra, extra);
  }
  cout << base + bestExtra << '\n';
  return 0;
}
