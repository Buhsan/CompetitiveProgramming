#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void marc (vector<vector<bool>> &visited, int i, int j, int width, int height, int w, int h) {
  int n = min(w, i + width);
  int m = min(h, j + height);
  //cout << "n: " << n << " m: " << m << endl;
  int orgJ = j;
  int orgI = i;

  for (int i = orgI; i < n; i++) {
    for (int j = orgJ; j < m; j++) {
      visited[i][j] = true;
      //cout << "visited[" << i << "][" << j << "]\n";
    }
  }
}


int calc(vector<vector<bool>> &visited) {
  int res = 0;
  int n = visited.size();
  int m = visited[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) res++;
    }
  }

  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h, n;
  while (cin >> w >> h >> n && (w || h || n)) {
    vector<vector<bool>> taken(w, vector<bool>(h));
    for (int i = 0; i < n; i++) {
      ll xi, yi, wi, hi;
      cin >> xi >> yi >> wi >> hi;
      marc(taken, xi, yi, wi, hi, w, h);
    }

    cout << calc(taken) << '\n';
  }
  return 0;
}




