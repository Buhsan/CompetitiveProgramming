#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> fib(50);


// int fib(int n) {
//   if (n == 0) return 0;
//   if (n == 1) return 1;
//   if (n == 2) return 1;
//   if (n == 3) return 1;
// }

unordered_map<ll,int> fibToBit;

void baseTrans(int n, vector<ll> &res) {
  while (!fibToBit.count(n)) {
    int fibi = *prev(upper_bound(fib.begin(), fib.end(), n));
    n-=fibi;
    res.push_back(fibi);
  }
  if (fibToBit.count(n)){
    res.push_back(n);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fib[0] = 1, fibToBit[1] = 0;
  fib[1] = 2, fibToBit[2] = 1;
  fib[2] = 3, fibToBit[3] = 2;
  fib[3] = 5, fibToBit[5] = 3;
  for (int i = 4; i < 50; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    fibToBit[fib[i]] = i;
  }

  int t; cin >> t;
  for (int tt = 0; tt < t; tt++) {
    ll n; cin >> n;
    if (!n) {
      cout << "0 = 0 (fib)" << (tt == t-1 ? "\n" : "\n");
      continue;
    }
    vector<ll> res;
    baseTrans(n, res);
    ll ans = 0;
    for (int i = res.size()-1; i >= 0; i--) {
      // cout << res[i] << " ";
      ans |= (1LL << fibToBit[res[i]]);
    }
    // cout << endl;
    // cout << "ans: " << ans << endl;
    int maxBit = fibToBit[res[0]];
    cout << n << " = ";
    for (int i = maxBit; i >= 0; i--) {
      if (ans & (1LL << i)) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << " (fib)" << (tt == t-1 ? "\n" : "\n");
  }

  return 0;
}
