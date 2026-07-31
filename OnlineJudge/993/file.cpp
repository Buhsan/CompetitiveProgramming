#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> factor(ll n) {
  ll num = n;
  vector<ll> res;
  for (ll i = 2; i*i <= n; i++) {
    while (num % i == 0) {
      res.push_back(i);
      num/=i;
    }
  }

  if (num > 1) res.push_back(num);
  sort(res.begin(), res.end());
  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<ll> digits = factor(n);
    /*cout << "digits" << endl;
      for (int i : digits) {
      cout << i << " ";
      }
      cout << endl;*/
    vector<ll> res;
    ll num = 1;
    bool possible = true;
    for (int i = 0; i < digits.size(); i++) {
      if (digits[i] > 9) {possible = false; break;}
      ll a = num*digits[i];
      if (a <= 9) {
        num = a;
      } else {
        res.push_back(num);
        num = digits[i];
      }
    }
    if (possible) {
      res.push_back(num);
      sort(res.begin(), res.end());
      for (int i = 0; i < res.size(); i++) {
        cout << res[i];
      }
      cout << endl;
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
