#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    map<string, int> grades;
    for (int i = 0; i < n; i++) {
      string trash; getline(cin, trash);
      string name;
      getline(cin, name);
      //cout << "name: " << name << endl;
      string result; cin >> result;
      grades[name] += (result == "CORRECTO" ? 1 : -1);
    }

    for (pair<string,int> p : grades) {
      if (p.second == 0) continue;
      cout << p.first << ", " << p.second << '\n';
    }
    cout << "---\n";
  }

  return 0;
}
