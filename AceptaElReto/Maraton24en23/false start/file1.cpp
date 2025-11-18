#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m && (n && m)) {
    cin.ignore();
    string separator(m + 2, '-');
    vector<string> matrix(m, string(n, ' '));
    vector<string> res(n, string(m, ' '));
    string s;
    for (int i = 0; i < m + 2; i++) {
      getline(cin, s);
      for (int j = 0; j < n + 2; j++) {
        if (i == 0 || i == m + 1) {
          break;
        }
        if (j == 0 || j == n + 1)
          continue;
        matrix[i - 1][j - 1] = s[j];
        // res[(n - 1) - (j - 1)][i - 1] = s[j];
      }
    }
    for (int i = 0; i < n + 2; i++) {
      for (int j = 0; j < m + 2; j++) {
        if (i == 0 || i == n + 1) {
          cout << separator << endl;
          break;
        } else if (j == 0 || j == m + 1) {
          if (j == 0)
            cout << '|';
          else
            cout << '|' << endl;
        } else {
          // cout << res[i - 1][j - 1];
          cout << matrix[j - 1][i - 1];
        }
      }
    }
  }

  return 0;
}
