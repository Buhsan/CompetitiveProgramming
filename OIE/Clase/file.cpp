#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dirs = {{-1,-1}, {-1,-1}, {}, {}, {}};

int main() {
  int n, m;
  int numeroTablero = 0;
  while (cin >> n >> m) {
    numeroTablero++;
    // 0 1
    if (n == 0 || !m) {
      break;
    }
    vector<vector<int>> v(n, vector<int>(m, 0));
    // v[0][1]
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> v[i][j];
     }
    }

    cout << "Tablero: " << numeroTablero << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << v[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
