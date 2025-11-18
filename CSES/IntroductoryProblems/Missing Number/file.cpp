#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  long long num = n * ((n+1)/2.0);
  long long sum = 0;
  for (int i = 0; i < n-1; i++) {
    int a; cin >> a;
    sum += a;
  }
  cout << (long long)(num - sum) << '\n';
  return 0;
}
