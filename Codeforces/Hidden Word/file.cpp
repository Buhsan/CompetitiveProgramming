#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  map<char, int> freq;
  
  for (int i = 0; i < n; i++) {
    freq[s[i]]++;
  }

  vector<int> reps;
  vector<char> ady;
  for (int i = 0; i < n; i++) {
    if (freq[s[i]] == 2) {
      reps.push_back(i);

      if (i - 1 >= 0) {
        ady.push_back(s[i - 1]);
      }

      if (i + 1 < n) {
        ady.push_back(s[i + 1]);
      }
    }
  }

  int dist = reps[1] - reps[0] - 1;
  int ad = ady.size();

  if (dist == 0) {
    cout << "Impossible\n";
    return 0;
  }

  int N = 2;
  int M = n / 2;
  char charRep = s[reps[0]];
  vector<vector<char>> grid(2, vector<char>(n / 2, ' '));
  if (dist % 2) {
    int startI = 0;
    int startJ = n / 2 - (dist + 1) / 2;

    grid[startI][startJ] = charRep;

    int currI = 0;
    int currJ = startJ;
    int dir = 0; // 0 para derecha, 1 izquierda
    int pathIdx = reps[0] + 1;

    while (currI != 1 || currJ != startJ) {
      // cout << currI << " " << currJ << " " << dir << " " << pathIdx << endl;

      if (dir == 0) {
        if (currJ == M - 1) {
          dir = 1;
          currI++;
        } else {
          currJ++;
        }
      } else if (dir == 1) {
        currJ--;
      }
      grid[currI][currJ] = s[pathIdx];

      pathIdx++;
    }

    pathIdx = reps[1] + 1;
    currI = startI;
    currJ = startJ;

    dir = 1;
    if (pathIdx == n) pathIdx = 0;
    while (pathIdx != reps[0]) {
      if (dir == 1) {
        if (currJ == 0) {
          dir = 0;
          currI++;
        } else {
          currJ--;
        }
      } else if (dir == 0) {
        currJ++;
      }
      grid[currI][currJ] = s[pathIdx];
      pathIdx++;

      if (pathIdx == n) {
        pathIdx = 0;
      }
    }
  } else {
    int startI = 0;
    int startJ = n / 2 - (dist + 2) / 2;

    grid[startI][startJ] = charRep;

    int currI = 0;
    int currJ = startJ;
    int dir = 0; // 0 para derecha, 1 izquierda
    int pathIdx = reps[0] + 1;

    while (currI != 1 || currJ != startJ) {
      if (dir == 0) {
        if (currJ == M - 1) {
          dir = 1;
          currI++;
        } else {
          currJ++;
        }
      } else if (dir == 1) {
        currJ--;
      }
      grid[currI][currJ] = s[pathIdx];

      pathIdx++;
    }

    pathIdx = reps[1] + 1;
    currI = startI;
    currJ = startJ;

    dir = 1;
    if (pathIdx == n) pathIdx = 0;
    while (pathIdx != reps[0]) {
      if (dir == 1) {
        if (currJ == 0) {
          dir = 0;
          currI++;
        } else {
          currJ--;
        }
      } else if (dir == 0) {
        currJ++;
      }
      grid[currI][currJ] = s[pathIdx];
      pathIdx++;

      if (pathIdx == n) {
        pathIdx = 0;
      }
    }

  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }

  return 0;
}
