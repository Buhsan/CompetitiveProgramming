#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    stack<int> entrada;
    vector<int> salida;
    stack<int> despila;
    for (int i = n; i >= 1; i--) {
      entrada.push(i);
    }

    int index = 0;
    int curr = -1;
    while (!entrada.empty() || !despila.empty()) {
      if (!entrada.empty()) {
        curr = entrada.top();
        // cout << "current: " << curr << endl;
        if (curr == a[index]) {
          // cout << "addding directly: " << curr << endl;
          salida.push_back(curr);
          entrada.pop();
          index++;
        } else if (!despila.empty() && despila.top() == a[index]) {
          // cout << "adding from the stack: " << despila.top() << endl;
          salida.push_back(despila.top());
          despila.pop();
          index++;
        } else {
          // cout << "addding to the stack: " << curr << endl;
          despila.push(curr);
          entrada.pop();
        }
      } else if (!despila.empty()) {
        // cout << "poping from the stack: " << despila.top() << endl;
        salida.push_back(despila.top());
        despila.pop();
      }
    }

    cout << (a == salida ? "SI" : "NO") << endl;
  }
  return 0;
}
