#include <bits/stdc++.h>
#include <random>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  random_device rd;
  mt19937 gen(rd());
  int t = 30;
  while (t--) {
    int n = 3;
    vector<int> sol;
    uniform_int_distribution<> distrib(0, n);
    int sum = 0;
    int maxi = 0;
    int length = 0;
    for (int i = 0; i < n; i++) {
      int a = distrib(gen);
      cout << a << " ";
      sum+=a;
      maxi = max(maxi, a);
      if (a) length++;
    }
    cout<<"\n";
    int res = 0;
    if (abs(sum-n)) res = min(length, max(length, abs(sum-n)));
    // if (abs(sum-n)) res = min(length, abs(sum-n));
    // if (abs(sum-n)) res = min(length, maxi); 
    else res = 1;
    cout << res << '\n';
  }


  return 0;
}

