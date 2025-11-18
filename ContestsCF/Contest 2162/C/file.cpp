#include <bits/stdc++.h>

using namespace std;
int xnor(int a, int b) {
  if (a == 0 && b == 0) 
    return 1; 

  int a_last = 0; 
  int b_last = 0; 
  int count = 0; 
  int xnornum = 0;
  while (a) {
    a_last = a & 1; 
    b_last = b & 1; 
    if (a_last == b_last) {
      xnornum |= (1 << count);
    }
    count++; 
    a = a >> 1;
    b = b >> 1; 
  }
  return xnornum;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    long long a, b; cin >> a >> b;
    if ((int)log2(a) < (int)log2(b)) cout << -1 << '\n';
    else if (a == b) cout << 1 << '\n' << 0 << '\n';
    else {
      long long num = a ^ b;
      if (num > a) {
        cout << 2 << '\n';
        long long  p = log2(num);
        long long nnum = (1 << p);
        long long nnnum = num - nnum;
        cout << nnnum << " " << nnum << '\n';
      } else {
        cout << 1 << '\n';
        cout << num << '\n';
      }
    }
  }
  return 0;
}
