#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(3*n);
    int high = 3*n;
    int low = 1;
    for (int i = 0; i < 3*n; i+=3) {
      v[i] = high;
      high--;
      v[i+1] = high;
      high--;
      v[i+2] = low;
      low+=1;
    }

    for (int i = 0; i < 3*n; i++) {
      cout << v[i] << " ";
    }
    cout << '\n';
    
  }
  return 0;
}
