#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m && (n || m)) {
    vector<pair<int,int>> mejiones;
    vector<pair<int,int>> gambas;
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      mejiones.push_back({a,b});
    }

    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      gambas.push_back({a,b});
    }

    bool res = false;
    for (int i = 0; i < m; i++) {
      pair<int,int> lineGamba = {-gambas[i].second, gambas[i].first};
      int rightG = 0, rightM = 0, leftG = 0, leftM = 0;
      for (int i = 0; i < m; i++) {
        double distGamba = lineGamba.first*gambas[i].first + lineGamba.second*gambas[i].second;
        if (distGamba > 0) rightG++;
        else if (distGamba < 0) leftG++;
      }

      for (int i = 0; i < n; i++) {
        double distMejion = lineGamba.first*mejiones[i].first + lineGamba.second*mejiones[i].second;
        if (distMejion > 0) rightM++;
        else if (distMejion < 0) leftM++;
      }

      if ((rightG+1 == leftG && rightM == leftM) || (rightG == leftG+1 && rightM == leftM)) {
        res = true;
        break;
      }

    }

    if (!res) {
      for (int i = 0; i < n; i++) {
        pair<int,int> lineMejion = {-mejiones[i].second, mejiones[i].first};
        int rightG = 0, rightM = 0, leftG = 0, leftM = 0;
        for (int i = 0; i < m; i++) {
          double distGamba = lineMejion.first*gambas[i].first + lineMejion.second*gambas[i].second;
          if (distGamba > 0) rightG++;
          else if (distGamba < 0) leftG++;
        }

        for (int i = 0; i < n; i++) {
          double distMejion = lineMejion.first*mejiones[i].first + lineMejion.second*mejiones[i].second;
          if (distMejion > 0) rightM++;
          else if (distMejion < 0) leftM++;
        }

        if ((rightG == leftG && rightM+1 == leftM) || (rightG == leftG && rightM == leftM+1)) {
          res = true;
          break;
        }
      }
    }

    cout << (res ? "SI" : "NO") << '\n';
  }
  return 0;
}
