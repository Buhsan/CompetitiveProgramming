#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >>t;
  while(t--) {
    int n; cin >> n;
    long long c; cin >> c;
    long double sum = 0;
    long double squareSum = 0;

    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      sum += a;
      squareSum += (a*a);
    }

    long double x1 = ( -((long double)4.0*sum) + sqrt( ((4*sum) * (4*sum)) - (16*(long double)n * (squareSum - (long double)c))))/((long double)8.0*n);

    // cout << fixed << setprecision(0) << x1 << '\n'; 
    cout << (long long) x1 << '\n'; 
  }

  return 0;
}
