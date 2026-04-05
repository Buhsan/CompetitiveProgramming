#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  double d;

  cin >> n >> m >> d;

  unordered_map<string, int> nameToId;
  vector<string> idToName(n);


  for (int i = 0; i < n; i++) {
    cin >> idToName[i];
    nameToId[idToName[i]] = i;
  }

  vector<vector<double>> dist(n, vector<double>(n, DBL_MAX));
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0.0;
  }

  for (int i = 0; i < m; i++) {
    string uName, vName;
    double w;
    cin >> uName >> vName >> w;
    int u = nameToId[uName];
    int v = nameToId[vName];

    dist[u][v] = w;
    dist[v][u] = w;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] != DBL_MAX && dist[k][j] != DBL_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }

  int q;
  cin >> q;

  while (q--) {
    string uName, vName;
    cin >> uName >> vName;

    int u = nameToId[uName];
    int v = nameToId[vName];

    vector<string> valid;
    for (int i = 0; i < n; ++i) {
      if (dist[u][i] != DBL_MAX && dist[v][i] != DBL_MAX) { 
        if (abs(dist[u][i] - dist[v][i]) <= d + 1e-9) {
          valid.push_back(idToName[i]);
        }
      }
    }

    sort(valid.begin(), valid.end());

    cout << valid.size() << "\n";
    for (const string& place : valid) {
      cout << place << "\n";
    }
  }





  return 0;
}
