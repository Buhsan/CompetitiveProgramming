#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> primes;
  primes.push_back(1);
  int limit = 1000;
  vector<bool> bprimes(limit, true);
  bprimes[1] = true;
  for (int i = 2; i < limit; i++) {
    if (bprimes[i]) {
      for (int j = 2*i; j < limit; j+=i) {
        bprimes[j] = false;
      }
    }
  }

  for (int i = 2; i < limit; i++) {
    if (bprimes[i]) primes.push_back(i);
  }

  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i] << " ";
  }
  cout << endl;

  int n, c;
  while (cin >> n >> c) {
    cout << n << " " << c << ": " << endl;
    auto it = upper_bound(primes.begin(), primes.end(), n);
    it = prev(it);
    int id = it - primes.begin();
    int cnt = 2*c;
    if ((id+1)%2) {
      int num = id/2 + 1;
      int rest = (cnt-1)/2;
      for (int i = num-rest; i <= id; i++) {
        cout << primes[i] << " ";
      }
    } else {
      int num = id/2 + 1;
      int rest = (cnt-1)/2;
      for (int i = num-rest; i <= id; i++) {
        cout << primes[i] << " ";
      }
    }
    cout << endl;
  }




  return 0;
}
