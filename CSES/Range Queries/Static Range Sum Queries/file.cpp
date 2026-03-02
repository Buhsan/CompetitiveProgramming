#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> pref;

ll query (int left, int right) {
  return pref[right] - (left-1 >= 0 ? pref[left-1] : 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q; cin >> n >> q;

  ll sum = 0;
  pref = vector<ll>(n);
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    sum+=a;
    pref[i] = sum;
  }

  for (int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    cout << (ll)query(a-1,b-1) << endl;
  }



  return 0;
}
