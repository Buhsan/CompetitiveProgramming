#include <bits/stdc++.h>

using namespace std;


bool check(int n) {
  while (n > 0) {
    if (n%10 != 1 && n%10 != 0) return false;
    n/=10;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N = 10001;

  int dp[N];
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i < N; i++) {
    //cout << "checking " << i << endl;
    int aux = INT_MAX;
    dp[i] = 0;
    if (check(i)) {
      //cout << "VALID" << endl;
      continue;
    }
    for (int j = 1; j <= i-1; j++) { 
      int sum = dp[i-j] + dp[j] + 1;
      int mult = (i%j==0 && j > 1 ? dp[i/j] + dp[j] + 1 : INT_MAX);
      //cout << "cost of " << i-j << " + " << j << " is: " << sum << endl;
      //cout << "cost of " << i/j << " * " << j << " is: " << mult << endl;
      aux = min({
        sum, mult, aux
      });
    }
    //cout << "the result is: " << aux << endl;
    dp[i] = aux;
  }

  int n;
  while (cin >> n && n) {
    cout << dp[n] << '\n';
  }
   
  return 0;
}

