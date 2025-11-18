#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  unordered_map<int, vector<int>> freq;

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    freq[a%2].push_back(i+1);
  }
  cout << (freq[0].size() == 1 ? freq[0][0] : freq[1][0]) << '\n';
  return 0;
}
