#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> sol;
    string s;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') sol.push_back(i+1);
    }
    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); i++) {
      cout << sol[i] << ' ';
    }
    cout << '\n';
  }





  return 0;
}
