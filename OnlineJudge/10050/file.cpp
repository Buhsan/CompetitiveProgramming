#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> days(3650);
  for (int i = 0; i < days.size(); i++) {
    days[i] = i % 7;
  }
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    int p; cin >> p;
    unordered_set<int> vis;
    for (int i = 0; i < p; i++) {
      int h; cin >> h;
      int curr = h-1;
      while (curr < n) {
        if (days[curr] != 5 && days[curr] != 6) vis.insert(curr);
        curr += h;
      }
    }
    cout << vis.size() << '\n';
  }
  return 0;
}
