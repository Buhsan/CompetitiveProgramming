#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

//dirs: 0-right, 1-left, 2-up, 3-down

pair<ll, ll> infoI(ll i) {
  return {(i%2 ? (i+1)*(i+1) : i*i+1), (i%2 ? 1 : 0)};
}

pair<ll, ll> infoJ(ll j) {
  return {(j%2 ? j*j +1 : (j+1)*(j+1)), (j%2 ? 3 : 2)};
}

ll solve(ll i, ll j) {
  if (i == 0) return infoJ(j).first;
  if (j == 0) return infoI(i).first;
  if (i==0 && j == 0) return 1;
  pair<ll, ll> a = infoI(i);
  pair<ll, ll> b = infoJ(j);
  ll res = 0;

  if (a.second % 2) {
    if (j <= i) res = (infoJ(i).first + i) + (i - j);
    else {
      if (b.second % 2) res = b.first + i;
      else res = b.first - i;
    }

  } else {
    if (j <= i) res = a.first + j;
    else {
      if (b.second % 2) res = b.first + i;
      else res = b.first - i;
    }
  }


  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    cout << solve(i,j) << '\n';
  }


  return 0;
}
