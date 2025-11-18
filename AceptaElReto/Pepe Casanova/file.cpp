#include <bits/stdc++.h>

using namespace std;

struct Cinta {
  int duracion;
  int puntuacion;
};

int main() {
  int n;
  while (cin >> n && n) {
    int longCinta;
    cin >> longCinta;

    vector<Cinta> cintas(n);
    for (int i = 0; i < n; i++) {
      cin >> cintas[i].duracion >> cintas[i].puntuacion;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(longCinta + 1, vector<int>(longCinta + 1)));

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= longCinta; j++) {
        for (int k = 0; k <= longCinta; k++) {
          dp[i][j][k] = max({
            dp[i - 1][j][k],
            (j - cintas[i - 1].duracion >= 0 ? dp[i - 1][j - cintas[i - 1].duracion][k] + cintas[i - 1].puntuacion : INT_MIN),
            (k - cintas[i - 1].duracion >= 0 ? dp[i - 1][j][k - cintas[i - 1].duracion] + cintas[i - 1].puntuacion : INT_MIN)
          });
        }
      }
    }
    // cout << "A" << endl;
    cout << dp[n][longCinta][longCinta] << endl;
  }
}
