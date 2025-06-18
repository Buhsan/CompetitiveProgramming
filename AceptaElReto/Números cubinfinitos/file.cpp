#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int sumDigits(ll n) {
  ll sum = 0;
  while (n > 0) {
    sum += ((n % 10) * (n % 10) * (n % 10));
    n /= 10;
  }
  return sum;
}

bool result(int n) {
  unordered_set<int> visited;
  while (true) {
    cout << n;
    if (n == 1) {
      cout << " -> cubifinito." << endl;
      return true;
    }
    if (visited.count(n)) {
      cout << " -> no cubifinito." << endl;
      return false;
    }
    visited.insert(n);
    n = sumDigits(n);
    cout << " - ";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    result(n);
  }
  return 0;
}
