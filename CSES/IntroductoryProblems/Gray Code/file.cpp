#include <bits/stdc++.h>

using namespace std;

int hamming(string a, string b) {
  int n = a.size();
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) res++;
  }
  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<string> res;
  for (int i = 0; i < (1 << n); i++) {
    string s;
    for (int j = n - 1; j >= 0; --j)
      s += ((i >> j) & 1) ? '1' : '0';
    res.push_back(s);
  }

  sort(res.begin(), res.end(), [&](string a, string b) {return hamming(a,b) == 1;});

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << '\n';
  }

  return 0;
}
