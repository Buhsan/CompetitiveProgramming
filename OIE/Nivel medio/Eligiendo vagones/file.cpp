#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
ios::sync_with_stdio(0);
  cin.tie(0);
  int p, n;
  while (cin >> p >> n && (p && n)) {
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
      cin >> input[i];
    }

    int start = 0;
    int end = 0;
    ll sum = 0;
    pair<int,int> res = {INT_MAX, -1};
    bool zero = 0;
    bool last = 0;
    
    while (start <= end) {
      // cout << start+1 << " " << end+1 << endl;
      if (!last) sum += input[end];
      if (end == n-1) last = true;
      if (!input[end]) {
        if (end < n-1) {
          start = end+1;
          sum = 0;
        } else if (end == n-1) {
          end--;
          zero = true;
        }
      }
      if (sum >= p) {
       // cout << "entering to move start with len: " << end-start+1 << " and sum: " << sum << endl;
        while(start <= end && sum >= p) {
          int len = end-start+1;
          // cout << "moving start: " << start+1 << " " << end+1 << " len: " << len << " sum: " << sum <<  endl;
          if ((len < res.first) || (res.first == end-start+1 && start+1 < res.second)) {
            // cout << "changing the best solution to ";
            res = {end-start+1, start+1};
            // cout << res.first << " " << res.second << endl;
          }
          sum-=input[start];
          start++;
        }
      }
      if (start == end && end == n-1) break;
      if (!zero && end+1 < n) {
        end++;
      } else {
        sum-=input[start];
        start++;
      }
    }

    if (res.first == INT_MAX) {
      cout << "NO ENTRAN" << '\n';
    } else {
      cout << res.first << " " << res.second << endl;
    }
  }
  return 0;
}
