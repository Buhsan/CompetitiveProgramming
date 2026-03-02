#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k; 
  while (cin >> n >> k && (n && k)) {
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
      cin >> input[i];
    }

    int start = 0;
    int end = 0;
    pair<int,long long> res = {-1,LLONG_MIN};
    long long sum = 0;

    while (end < n) {
      sum+=input[end];
      if (end-start+1 == k) {
        if ((sum > res.second) || (sum == res.second && start+1 > res.first)) res = {start+1,sum};
        sum-=input[start];
        start++;
      }
      end++;
    }
    cout << res.first << " " << res.second << '\n';
  }

  return 0;
}
