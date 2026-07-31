#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

vector<int> printDivisors(int n) {
  vector<int>divisors;

  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {

      if (n / i == i) {
        divisors.push_back(i) ;
      }
      else {
        divisors.push_back(i) ;
        divisors.push_back(n/i) ;
      }
    }
  }

  return divisors;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  while (cin >> k) {
    int n = 10000;
    double res = 1.0 / k;
    vector<pair<int,int>> sol;
    vector<int> div = printDivisors(k);
    sort(div.begin(), div.end());

    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
        double num = (double)(1.0 / i) + (double)(1.0 / j);
        if (abs(res-num) <= EPS) {
          sol.push_back({i,j});
        }
      }
    }
    cout << "Solution for 1 / " << k << ": ";
    for (int d : div) {
      cout << d << " ";
    }
    cout << endl;
    int cnt = 1;
    for (pair p : sol) {
      int num = (p.first * k) / p.second;
      cout << "1 / " << p.first << " + " << "1 / " << p.second << " (" << num << ")" << endl;
      cnt++;
      if (p.first == p.second) break;
    }
    cout << endl;
  }


  return 0;
}
