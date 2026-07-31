#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  while (cin >> x) {
    vector<vector<int>> grid(5, vector<int>(5)), original(5, vector<int>(5));
    grid[0][0] = x;

    original[0][0] = x;

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (i == 0 && j == 0) continue;
        cin >> grid[i][j];

        original[i][j] = grid[i][j];
      }
    }

    bool found = false;

    while (cin >> x && x) {
      if (found) continue;

      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          if (grid[i][j] == x) grid[i][j] = 0;
        }
      }

      for (int i = 0; i < 5; i++) {
        bool allZeros = true;
        for (int j = 0; j < 5; j++) {
          if (grid[i][j]) {
            allZeros = false;
            break;
          }
        }

        if (allZeros) {
          found = true;
          cout << "BINGO #1\n";

          for (int j = 0; j < 5; j++) {
            cout << i + 1 << "," << j + 1 << "," << (original[i][j] == 0 ? "FREE" : to_string(original[i][j])) << "\n";
          }
        }
      }

      for (int j = 0; j < 5; j++) {
        bool allZeros = true;
        for (int i = 0; i < 5; i++) {
          if (grid[i][j]) {
            allZeros = false;
            break;
          }
        }

        if (allZeros) {
          found = true;
          cout << "BINGO #2\n";

          for (int i = 0; i < 5; i++) {
            cout << i + 1 << "," << j + 1 << "," << (original[i][j] == 0 ? "FREE" : to_string(original[i][j])) << "\n";
          }
        }
      }

      if (grid[0][0] == 0 && grid[0][4] == 0 && grid[4][0] == 0 && grid[4][4] == 0) {
        found = true;
        cout << "BINGO #3\n";

        cout << 1 << "," << 1 << "," << (original[0][0] == 0 ? "FREE" : to_string(original[0][0])) << "\n";
        cout << 1 << "," << 5 << "," << (original[0][4] == 0 ? "FREE" : to_string(original[0][4])) << "\n";
        cout << 5 << "," << 1 << "," << (original[4][0] == 0 ? "FREE" : to_string(original[4][0])) << "\n";
        cout << 5 << "," << 5 << "," << (original[4][4] == 0 ? "FREE" : to_string(original[4][4])) << "\n";
      }


      {
        // segunda diagonal
        bool allZeros = true;
        for (int i = 0; i < 5; i++) {
          if (grid[i][5 - i - 1]) {
            allZeros = false;
            break;
          }
        }

        if (allZeros) {
          found = true;
          cout << "BINGO #4\n";

          for (int i = 0; i < 5; i++) {
            cout << i + 1 << "," << 5 - i + 1 - 1<< "," << (original[i][5 - i - 1] == 0 ? "FREE" : to_string(original[i][5 - i - 1])) << "\n";

          }
        }

      }

      {
        // primera diagonal
        bool allZeros = true;
        for (int i = 0; i < 5; i++) {
          if (grid[i][i]) {
            allZeros = false;
            break;
          }
        }

        if (allZeros) {
          found = true;
          cout << "BINGO #4\n";

          for (int i = 0; i < 5; i++) {
            cout << i + 1 << "," << i + 1 << "," << (original[i][i] == 0 ? "FREE" : to_string(original[i][i])) << "\n";
          }
        }

      }

    }

    if (!found) {
      cout << "No BINGO on this card.\n";
    }
    cout << "\n";
  }


  return 0;
}
