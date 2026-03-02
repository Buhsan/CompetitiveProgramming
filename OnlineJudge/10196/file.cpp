#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> pawnB = {{-1,1}, {-1,-1}};
vector<pair<int,int>> pawnW = {{1,1}, {1,-1}};
vector<pair<int,int>> knight = {{2,1}, {2,-1}, {1, -2}, {1, 2}, {-2, 1}, {-2,-1}, {-1, 2}, {-1, -2}};
vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0},{-1,0}, {-1,1}, {-1,-1}, {1,-1}, {1,1}};
// [0,1] - horizontal
// [2,3] - vertical
// [4,7] - diagonals 

bool check(pair<int,int> king, const vector<string> &board, bool black) {
  // check white/black pawn
  int n, m;
  n = 8;
  // cout << "test init" << endl;
  if (black) {
    for (pair<int,int> d : pawnW) {
      int ni = king.first + d.first;
      int nj = king.second + d.second;
      if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == 'P') return true;
    }
  } else {
    for (pair<int,int> d : pawnB) {
      int ni = king.first + d.first;
      int nj = king.second + d.second;
      if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == 'p') return true;
    }
  }

  //check knight
  for (pair<int,int> d : knight) {
    int ni = king.first + d.first;
    int nj = king.second + d.second;
    if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == (black ? 'N' : 'n')) return true;
  }
  
  // check horizontal

  for (int i = 0; i < dirs.size(); i++) {
    // cout << "moving into direction " << i << endl;
    pair<int,int> d = dirs[i];
    int ni = king.first + d.first; 
    int nj = king.second + d.second;
    while (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == '.'){
      ni += d.first;
      nj += d.second;
    }
    if (!(ni >= 0 && ni < n && nj >= 0 && nj < n)) continue;
    // cout << "found a peace: " << board[ni][nj] << endl;
    if ((i == 0 || i == 1 || i == 2 || i == 3) && (board[ni][nj] == (black ? 'R' : 'r') || board[ni][nj] == (black ? 'Q' : 'q'))) return true;
    if ((i == 4 || i == 5 || i == 6 || i == 7) && (board[ni][nj] == (black ? 'B' : 'b') || board[ni][nj] == (black ? 'Q' : 'q'))) return true;
  }

  return false;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (true) {
    vector<string> board;
    string s;
    int cntPieces = 0;
    int i = 0;
    pair<int,int> whiteKing, blackKing;
    while (getline(cin,s) && !s.empty()) {
      board.push_back(s);
      for (int j = 0; j < (int)s.size(); j++) {
        if (s[j] != '.') {
          cntPieces++;
          if (s[j] == 'k') {
            blackKing = {i,j};
          } else if (s[j] == 'K') {
            whiteKing = {i,j};
          }
        }
      }
      i++;
    }
    if (cntPieces == 0) break;
    // cout << "white: " << whiteKing.first << " " << whiteKing.second << endl;
    // cout << "black: " << blackKing.first << " " << blackKing.second << endl;
    // if (t > 1) cout << '\n';

    if (check(whiteKing, board, 0)) {
      cout << "Game #" << t << ": white king is in check.";
    } else if (check(blackKing, board, 1)) {
      cout << "Game #" << t << ": black king is in check.";
    } else {
      cout << "Game #" << t << ": no king is in check.";
    }
    cout << '\n';
    t++;
  }

  return 0;
}
