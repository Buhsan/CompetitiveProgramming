#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, id;
  while (cin >> n >> id && (n && id)) {
    int a, b;
    while(cin >> a >> b && (a && b)) {
      if (a == id) {
        id = b;
      }
      else if (b == id) {
        id = a;
      }
    }

    cout << id << '\n';
  }
  return 0;
}
