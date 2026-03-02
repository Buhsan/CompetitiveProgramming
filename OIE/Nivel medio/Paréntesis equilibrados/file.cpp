#include <bits/stdc++.h>

using namespace std;


bool isBalanced(string& s, char first, char second) {
  // cout << (char)first << " " << (char)second << endl;
  bool open = false; // solo es true cuando encuentro (, cuando cierro la pareja vuelve a ser false
  vector<int> st;
  int i = 0;
  int n = s.size();
  while (i < n) {
    if (!open && s[i] == second) return false;
    if (s[i] == first) {
      st.push_back(i);
      open = true;
    } else if (s[i] == second) {
      st.pop_back();
      open = !st.empty();

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
    bool res = true;

    vector<pair<char,char>> parent = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

    // cout << s << ": ";
    for (pair<int,int> p : parent) {
      res = isBalanced(s, (char)p.first, p.second);
      // cout << "for " << (char)p.first << " , " << (char)p.second << ": " << (res ? "true" : "false") << endl;
      if (!res) break;
    }

    cout << (res ? "SI" : "NO") << '\n';
  }

  return 0;
}
