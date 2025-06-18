#include "bits/stdc++.h"
using namespace std;

int countPawnBlack(vector<string> &tablero, int i, int j,
                   vector<vector<bool>> &attack) {
  vector<pair<int, int>> dirs = {{1, 1}, {1, -1}};
  int n = tablero.size();
  int res = 0;
  for (auto dir : dirs) {
    int newI = i + dir.first;
    int newJ = j + dir.second;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] == '0' && !attack[newI][newJ]) {
        res++;
        attack[newI][newJ] = true;
      }
    }
  }
  return res;
}

int countPawnWhite(vector<string> &tablero, int i, int j,
                   vector<vector<bool>> &attack) {
  vector<pair<int, int>> dirs = {{-1, 1}, {-1, -1}};
  int n = tablero.size();
  int res = 0;
  for (auto dir : dirs) {
    int newI = i + dir.first;
    int newJ = j + dir.second;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] == '0' && !attack[newI][newJ]) {
        res++;
        attack[newI][newJ] = true;
      }
    }
  }
  return res;
}

int countKing(vector<string> &tablero, int i, int j,
              vector<vector<bool>> &attack) {
  vector<pair<int, int>> dirs = {{-1, 1}, {-1, -1}, {1, 1},  {1, -1},
                                 {0, 1},  {0, -1},  {-1, 0}, {1, 0}};
  int n = tablero.size();
  int res = 0;
  for (auto dir : dirs) {
    int newI = i + dir.first;
    int newJ = j + dir.second;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] == '0' && !attack[newI][newJ]) {
        res++;
        attack[newI][newJ] = true;
      }
    }
  }
  return res;
}

int countKnight(vector<string> &tablero, int i, int j,
                vector<vector<bool>> &attack) {
  vector<pair<int, int>> dirs = {{2, 1},  {2, -1},  {1, 2},  {-1, 2},
                                 {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};
  int n = tablero.size();
  int res = 0;
  for (auto dir : dirs) {
    int newI = i + dir.first;
    int newJ = j + dir.second;
    if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] == '0' && !attack[newI][newJ]) {
        res++;
        attack[newI][newJ] = true;
      }
    }
  }
  return res;
}

int countRook(vector<string> &tablero, int i, int j,
              vector<vector<bool>> &attack) {
  int n = tablero.size();
  int res = 0;
  vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (auto dir : dirs) {
    int newI = i + dir.first, newJ = j + dir.second;
    while (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] != '0')
        break;
      if (!attack[newI][newJ]) {
        attack[newI][newJ] = true;
        res++;
      }
      newI += dir.first;
      newJ += dir.second;
    }
  }
  return res;
}

int countBishop(vector<string> &tablero, int i, int j,
                vector<vector<bool>> &attack) {
  int n = tablero.size();
  int res = 0;
  vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  for (auto dir : dirs) {
    int newI = i + dir.first, newJ = j + dir.second;
    while (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
      if (tablero[newI][newJ] != '0')
        break;
      if (!attack[newI][newJ]) {
        attack[newI][newJ] = true;
        res++;
      }
      newI += dir.first;
      newJ += dir.second;
    }
  }
  return res;
}

int countQueen(vector<string> &tablero, int i, int j,
               vector<vector<bool>> &attack) {
  int res = 0;
  res += countBishop(tablero, i, j, attack);
  res += countRook(tablero, i, j, attack);
  return res;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    vector<string> tablero;
    vector<vector<bool>> attack(8, vector<bool>(8));
    stringstream ss(s);
    int result = 64;
    while (getline(ss, s, '/')) {
      int n = s.size();
      string line;
      for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
          int num = s[i] - '0';
          for (int j = 0; j < num; j++) {
            line += '0';
          }
        } else {
          line += s[i];
          result--;
        }
      }
      tablero.push_back(line);
    }

    for (int i = 0; i < tablero.size(); i++) {
      for (int j = 0; j < tablero.size(); j++) {
        if (tablero[i][j] == 'p') {
          result -= countPawnBlack(tablero, i, j, attack);
        } else if (tablero[i][j] == 'P') {
          result -= countPawnWhite(tablero, i, j, attack);
        } else if (tablero[i][j] == 'n' || tablero[i][j] == 'N') {
          result -= countKnight(tablero, i, j, attack);
        } else if (tablero[i][j] == 'r' || tablero[i][j] == 'R') {
          result -= countRook(tablero, i, j, attack);
        } else if (tablero[i][j] == 'b' || tablero[i][j] == 'B') {
          result -= countBishop(tablero, i, j, attack);
        } else if (tablero[i][j] == 'q' || tablero[i][j] == 'Q') {
          result -= countQueen(tablero, i, j, attack);
        } else if (tablero[i][j] == 'K' || tablero[i][j] == 'k') {
          result -= countKing(tablero, i, j, attack);
        }
      }
    }
    cout << result << endl;

    // for (int i = 0; i < 8; i++) {
    //   for (int j = 0; j < 8; j++) {
    //     cout << tablero[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // cout << endl;
    // for (int i = 0; i < 8; i++) {
    //   for (int j = 0; j < 8; j++) {
    //     if (attack[i][j]) {
    //       cout << "X";
    //     } else
    //       cout << ".";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;
  }
}
