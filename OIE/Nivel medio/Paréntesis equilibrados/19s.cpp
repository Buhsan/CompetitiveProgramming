#include <bits/stdc++.h>

using namespace std;


bool isBalanced(string& s) {
  // bool open = false; // solo es true cuando encuentro (, cuando cierro la pareja vuelve a ser false
  stack<char> st;
  int i = 0;
  int n = s.size();
  while (i < n) {
    if (st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) return false;
    if ((s[i] == '(' || s[i] == '{' || s[i] == '[')) {
      st.push(s[i]);
    } else if ((s[i] == ')' || s[i] == '}' || s[i] == ']')) {
      char last = st.top();
      st.pop();
      if (last == '(' && s[i] != ')') return false;
      if (last == '[' && s[i] != ']') return false;
      if (last == '{' && s[i] != '}') return false;
    }
    i++;
  }

  if (!st.empty()) return false;

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while(getline(cin, s)) {
    // cout << s << ": ";
    cout << (isBalanced(s) ? "SI" : "NO") << '\n';
  }

  return 0;
}
