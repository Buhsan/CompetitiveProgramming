#include <bits/stdc++.h>

using namespace std;

string reverse1(string s) {
  string res(s.size(), '?');
  int j = s.size()-1;
  int id = 0;

  for (int i = 0; i < s.size(); i++) {
    if (i%2) {
      res[j] = s[i];
      j--;
    } else {
      res[id] = s[i];
      id++;
    }
  }
  return res;
}

string reverse2(string s) {
  string res = "";
  int n = s.size();
  string aux = "";
  for (int i = 0; i < n; i++) {
    char c = tolower(s[i]);
    if (c != 'a' && c != 'e' && c != 'u' && c != 'i' && c != 'o') {
      aux += s[i];
    } else {
      reverse(aux.begin(), aux.end());
      res += aux;
      res += s[i];
      aux = "";
    }
  }
  reverse(aux.begin(), aux.end());
  res+=aux;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (getline(cin, s)) {
    string a = reverse1(s);
    cout << reverse2(a) << '\n';
  }

  return 0;
}
