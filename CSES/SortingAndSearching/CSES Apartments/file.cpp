#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, k; cin >> n >> m >> k;
  vector<ll> desires(n);
  vector<ll> apartments(m);
  for (int i = 0; i < n; i++) {
    cin >> desires[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> apartments[i];
  }
  sort(desires.begin(), desires.end());
  sort(apartments.begin(), apartments.end());

  ll ans = 0;

  ll child = 0;
  ll ap = 0;

  while (child < n && ap < m) {
    ll a = desires[child] - k;
    ll b = desires[child] + k;

    if (apartments[ap] < a) {
      ap++;
      continue;
    }

    if (apartments[ap] > b) {
      child++;
      continue;
    }

    ans++;
    ap++;
    child++;

  }

  cout << ans << "\n";
  return 0;
}
