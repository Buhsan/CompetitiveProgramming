#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc (ll num) {
  ll res = 0;
  while (num > 0) {
    res += (num%10) * (num%10);
    num/=10;
  }

  return res;
}


unordered_map<ll, bool> memo;

bool check(ll num) {
  //cout << "starting check: " << num << endl;
  unordered_set<ll> visited;
  int good = -1;
  while (num > 1) {
    //cout << "num: " << num << endl;
    if (memo.count(num)) {
      good = memo[num];
      break;
    }
    //if (visited.count(num)) return memo[num] = false;
    memo[num] = false;
    visited.insert(num);
    num = calc(num);
  }
  if (good == 1) {
    //cout << "true" << endl;
   // cout << "so ";
    for (ll a : visited) {
      //cout << a << " ";
      memo[a] = true;
    }
    //cout << "are also true" << endl;
    return true;
  } else if (good == 0) {
    //cout << "false" << endl;
    return false;
  } else {
    //cout << "case -1, num is " << num << " so the result is " << (num==1 ? "true" : "false") << endl;
    if (num == 1) {
      //cout << "so ";
      for (ll a : visited) {
        //cout << a << " ";
        memo[a] = true;
      }
      //cout << "are also true" << endl;
    }
    return num == 1;
  }
}


int main() {
  ios::sync_with_stdio();
  cin.tie(0);
  memo[1] = true;

  for (int i = 2; i <= 10000; i++) {
    memo[i] = check(i);
  }

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    bool res = false;
    if (memo.count(n)) res = memo[n];
    else {
      res = memo[n] = check(n);
    }
    cout << (res ? "Feliz" : "Infeliz") << '\n';
  }


  return 0;
}
