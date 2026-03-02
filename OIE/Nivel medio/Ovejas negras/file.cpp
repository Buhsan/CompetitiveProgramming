#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int n, m;
vector<string> image;

void bfs(vector<vector<bool>> &visited) {
  queue<pair<int,int>> q;
  q.push({0,0});
  visited[0][0] = true;
  while (!q.empty()) {
    pair<int,int> curr = q.front();
    q.pop();
    for (pair<int,int> dir : dirs) {
      int newI = curr.first + dir.first;
      int newJ = curr.second + dir.second;

      if (newI >= 0 && newI < n && newJ >=0 && newJ < m && image[newI][newJ] == '.' && !visited[newI][newJ]) {
        visited[newI][newJ] = true;
        q.push({newI, newJ});
      }
    }
  }
}


bool isWhite(vector<vector<bool>> &visited) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (image[i][j] == '.' && !visited[i][j]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> m >> n) {
    cin.ignore();
    image.clear();
    for (int i = 0 ; i < n; i++) {
      string s; getline(cin,s);
      image.push_back(s);
    }
    vector<vector<bool>> visited (n,vector<bool>(m,0));
    bfs(visited);

    cout << (isWhite(visited) ? "SI" : "NO") << endl;
  }
  return 0;
}
