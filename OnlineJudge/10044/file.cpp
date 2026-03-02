#include <bits/stdc++.h>

using namespace std;


struct Paper{
  unordered_set<string> writers;
};

unordered_set<string> authors(string s) {
  char c = 'a';
  // vector<string> sol;
  unordered_set<string> sol;
  int n = s.size();
  int i = 0;
  string res = "";
  int spaces = 0;
  while (s[i] != ':') {
    if (i + 1 < n && s[i] == ',' && s[i + 1] == ' ') {
      if (spaces == 1) {
        sol.insert(res);
        // sol.push_back(res);
        res = "";
        spaces = 0;
      } else {
        spaces = (spaces + 1) % 2;
        res += s[i];
        res += s[i + 1];
      }
      i += 2;
    } else {
      res += s[i];
      i++;
    }
  }
  sol.insert(res);
  // sol.push_back(res);
  return sol;
}

vector<vector<int>> adj;
int dfs(int u, int target, int step, vector<bool> &visited) {
  cout << "u: " << u << " step: " << step << endl;
  visited[u] = true;
  if (u == target) {
    return step;
  }

  int cnt = 0;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v, target, step+1, visited);
    }
  }
  return step;
}

struct Node{
  int id, erdos;
};


int bfs(int start, int target, vector<bool> visited) {
  queue<Node> q;
  q.push({start, 0});
  visited[start] = true;
  int res = 0;
  while (!q.empty()) {
    Node node = q.front();
    int u = node.id;
    int erdos = node.erdos;
    q.pop();

    if (u == target) {
      res = erdos;
      break;
    }

    for (int v : adj[u]) {
      if (!visited[v]) {
        q.push({v, erdos+1});
      }
    }
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int p, n;
    cin >> p >> n;
    cin.ignore();
    unordered_map<string, int> nameToId;
    // unordered_map<int, vector<string>> bookToName;
    vector<Paper> papers;
    for (int i = 0; i < p; i++) {
      string s; getline(cin,s);
      papers.push_back((Paper)authors(s));
    }
  }
  return 0;
}
