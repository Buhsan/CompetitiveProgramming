#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x; cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  int start = 0;
  int end = n-1;
  int cnt = 0;
  while (start <= end) {
    ll sum = a[start] + a[end];
    if (sum > x) end--;
    else start++, end--;
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
