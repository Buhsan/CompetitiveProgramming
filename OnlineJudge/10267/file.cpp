#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> img;
bool created = false;
vector<pair<int,int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> input;
  string s;
  while (getline(cin,s)  && !s.empty()) {
    stringstream ss(s);
    char cmd;
    ss >> cmd;
    // if (!(ss >> cmd)) continue;
    if (cmd == 'I') {
      created = true;
      int m,n;
      ss >> m >> n;
      // img.clear();
      img = vector<vector<char>>(n, vector<char>(m, 'O'));
    } else if (cmd == 'C' && created) {
      int a = img.size();
      int b = img[0].size();
      img = vector<vector<char>>(a, vector<char>(b, 'O'));
    } else if (cmd == 'L' && created) {
      int i, j;
      char c;
      ss >> j >> i >> c;
      j--, i--;
      img[i][j] = c;
    } else if (cmd == 'V' && created) {
      int j, i1, i2;
      char c;
      ss >> j >> i1 >> i2 >> c;
      j--, i1--, i2--;
      int low= min(i1,i2);
      int high = max(i1,i2);
      for (int i = low; i <= high; i++) {
        img[i][j] = c;
      }
    } else if (cmd == 'H' && created) {
      int i, j1, j2;
      char c;
      ss >> j1 >> j2 >> i >> c;
      j1--, j2--, i--;
      int low= min(j1,j2);
      int high = max(j1,j2);
      for (int j = low; j <= high; j++) {
        img[i][j] = c;
      }
    } else if (cmd == 'K' && created) {
      int i1, j1, i2, j2;
      char c;
      ss >> j1 >> i1 >> j2 >> i2 >> c;
      j1--, i1--, j2--, i2--;
      int minI = min(i1, i2);
      int maxI = max(i1,i2);
      int minJ = min(j1, j2);
      int maxJ = max(j1, j2);
      // int nn = i2 - i1 + 1;
      // int mm = j2 - j1 + 1;
      // img[i1][j1] = 'B';
      // img[i2][j2] = 'B';
      for (int i = minI; i <= maxI; i++) {
        for (int j = minJ; j <= maxJ; j++) {
          img[i][j] = c;
        }
      }
    } else if (cmd == 'F' && created) {
      int j, i;
      char c;
      ss >> j >> i >> c;
      j--, i--;
      int n = img.size();
      int m = img[0].size();
      char regionColor = img[i][j];
      queue<pair<int,int>> q;
      vector<vector<bool>> visited(img.size(), vector<bool> (img[0].size(), false));
      q.push({i,j});
      img[i][j] = c;
      visited[i][j] = true;
      while (!q.empty()) {
        pair<int,int> px = q.front();
        q.pop();

        for (pair<int,int> d : dirs) {
          int ni = px.first + d.first;
          int nj = px.second + d.second;
          if (ni >= 0 && ni < n && nj >= 0 && nj < m && img[ni][nj] == regionColor && !visited[ni][nj]) {
            visited[ni][nj] = true;
            img[ni][nj] = c;
            q.push({ni,nj});
          } 
        }
      }
    } else if (cmd == 'S' && created) {
      string name; ss >> name;
      cout << name << '\n';
      for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[0].size(); j++) {
          cout << img[i][j];
        }
        cout << '\n';
      }
    } else if (cmd == 'X') {
      created = false;
      break;
      // img.clear();
    }
  }
  return 0;
}
