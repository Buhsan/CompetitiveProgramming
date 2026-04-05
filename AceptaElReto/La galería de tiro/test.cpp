#include <iostream>

using namespace std;

const int MAX_DP = 500005;
int dp[MAX_DP];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;

  for (int i = 4; i <= 500000; i += 2) {
    int half = i >> 1;           
    int d_half = dp[half];       
    int d_next = dp[half + 1];

    dp[i] = d_next + d_half - 1;       
    dp[i + 1] = d_next + d_next - 1;   
  }

  int n;
  while (cin >> n && n) {
    if (n <= 500000) {
      cout << dp[n] << '\n';
    } else {
      int half = n >> 1;
      int d_half = dp[half];
      int d_next = dp[half + 1];

      if (n & 1) { 
        cout << d_next + d_next - 1 << '\n';
      } else { 
        cout << d_next + d_half - 1 << '\n';
      }
    }
  }

  return 0;
}
