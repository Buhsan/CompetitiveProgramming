#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  unordered_map<char, int> freq;
  for (int i = 0; i < n; i++) {
    freq[s[i]]++;
  }

  int cntOdd = 0;
  string odd = "";
  string res = "";
  string aux = "";
  for (auto p : freq) {
    if (p.second % 2) cntOdd++, odd = string(p.second, p.first);
    else {
      aux += string(p.second/2, p.first);
    };
    if (cntOdd > 1) break;
  }

  if (cntOdd <= 1) {
    res = aux + odd;
    reverse(aux.begin(), aux.end());
    res += aux;
  } else {
    res = "NO SOLUTION";
  }
  cout << res << "\n";

  return 0;
}


