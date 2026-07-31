//TODO
#include <bits/stdc++.h>
using namespace std;

bool factor(int n, set<int> &s) {
  bool res = true;
  for (int i = 2; i*i <= n; i++) {
    while(n%i == 0) {
      n/=i;
      if (!s.count(i) && i < 100) {s.insert(i);}
      else {res = false;}
    }
  }
  if (n > 1) {
    if (!s.count(n) && n < 100) {s.insert(n);}
    else {res = false;}
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int high, low;
  while (cin >> high >> low) {

    set<int> s1, s2;
    bool b1, b2;
    high = max(high, low);
    low = min(high, low);

    b1 = factor(high, s1);
    b2 = factor(low, s2);


    cout << "s1: ";
    for (int i : s1) {
      cout << i << " ";
    }
    cout << endl;
    cout << "s2: ";
    for (int i : s2) {
      cout << i << " ";
    }
    cout << endl;


    int res = low;
    if (!b1 || (!b1 && !b2)) {
      res = low;
    } else if (!b2) {
      res = high;
    } else {
      bool check = true;
      for (int div : s1) {
        if (!check) break;
        if (s2.count(div)) check = false;
      }
      if (check) res = high;
      else res = low;
    }

    cout << res << '\n';
    cout << endl;
  }


  return 0;
}


