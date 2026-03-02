#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isOper(string s) { return (s == "+") || (s == "-") || (s == "/") || (s == "*"); }


ll calc(string oper) {
  string a, b;
  if (!(cin >> a)) return 0;
  ll num1 = 0, num2 = 0;
  bool isNum1 = false, isNum2 = false;
  if (isOper(a)) {
    num1 = calc(a);
    isNum1 = true;
  }
  if (!(cin >> b)) return 0;
  if (isOper(b)) {
    num2 = calc(b);
    isNum2 = true;

  }


  if (!isNum1)   num1 = stoll(a);
  if (!isNum2)   num2 = stoll(b);

  ll res = 0;
  switch (oper[0]) {
    case '+':
      res = (long long)num1 + num2;
      break;
    case '-':
      res = (long long)num1 - num2;
      break;
    case '*':
      res =  (long long)num1 * num2;
      break;
    case '/':
      res = (long long)num1 / num2;
      break;
    default:
      break;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    if (cin >> s) {
      ll res = 0;
      if (isOper(s)) {
        res = calc(s);
        cout << res << '\n';
      } else {
        cout << s << '\n';

      }
    }
  }
  return 0;
}
