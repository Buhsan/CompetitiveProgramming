#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> favorites(m);
    unordered_set<int> nums;

    for (int i = 0; i < m; i++) {
      cin >> favorites[i];
      nums.insert(favorites[i]);
    }
    int ans = 1;

    bool sorted = false;
    vector<int> a(favorites.begin(), favorites.end());
    int k = *max_element(favorites.begin(), favorites.end());
    sort(a.begin(), a.end());

    if (m == nums.size() && favorites == a) {
      ans = n-k+1;
    }
    cout << ans << '\n';
  }

  return 0;
}
