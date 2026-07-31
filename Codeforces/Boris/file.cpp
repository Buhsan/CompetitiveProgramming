#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> v(n);
    map<int,int> freq;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      freq[v[i]]++;
    }
    vector<vector<ll>> medians(n, vector<ll>(n,-1));

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j+=2) {
        int len = j - i + 1;
        medians[i][j] = v[len/2];
      }
    }

  }

  return 0;
}
