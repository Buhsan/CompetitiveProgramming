#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
      cin >> in[i];
    }


    stack<int> thirds;
    int second = -1;

    bool res = true;

    for (int i = n-1; i >= 0; i--) {
      
      if (in[i] > second) {
        while (!thirds.empty() && in[i] > thirds.top()) {
          second = thirds.top();
          thirds.pop();
        }
        thirds.push(in[i]);
      } else {
        res = false;
        break;
      }
    }
    

    

    cout << (res ? "SIEMPRE PREMIO" : "ELEGIR OTRA") << '\n';

  }

  

  return 0;
}
