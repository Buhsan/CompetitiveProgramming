#include "bits/stdc++.h"
using namespace std;

int countPawnWhite(vector<string> &tablero, int i, int j,
                   vector<vector<bool>> &attack) {
  vector<pair<int, int>> dirs = {{1, 1}, {1, -1}};
  int n = tablero.size();
  int res = 0;
  for (auto dir : dirs) {
    int newI = i + dir.first;
    int newJ = j + dir.first;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] == '0' && !attack[newI][newJ]) {
        res++;
      }
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    vector<string> tablero;
    vector<vector<bool>> attack;
    tablero.clear();
    stringstream ss(s);
    while (getline(ss, s, '/')) {
      int n = s.size();
      string line;
      for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
          string aux(s[i] - '0', '0');
          line += aux;
        } else {
          line += s[i];
        }
      }
      tablero.push_back(line);
    }
    for (int i = 0; i < tablero.size(); i++) {
      for (int j = 0; j < tablero.size(); j++) {
        if (tablero[i][j] == 'p') {
        }
      }
    }
  }
}
