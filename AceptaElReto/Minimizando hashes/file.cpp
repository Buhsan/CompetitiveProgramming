#include <bits/stdc++.h>

using namespace std;


struct Node {
  int pos;
  int depth;
  vector<string> str;
};


pair<Node, Node> build (Node curr) {
  vector<string> input = curr.str;
  int pos = curr.pos + 1;
  Node leftA = {0, 0, {}}, rightB = {0, 0, {}}; 

  for (int i = 0; i < input.size(); i++) {
    if (pos >= input[i].size()) continue;
    if (input[i][pos] == 'a') {
      leftA.pos = pos;
      leftA.depth = curr.depth + 1;
      leftA.str.push_back(input[i]);
    } else {
      rightB.pos = pos;
      rightB.depth = curr.depth + 1;
      rightB.str.push_back(input[i]);
    }
  }

  return {leftA, rightB};
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<string> input(n);
    for (int i = 0; i < n; i++) {
      cin >> input[i];
      // cout << input[i] << '\n';
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }

    queue<Node> q;
    int pos = 0;
    auto p = build({-1, 0, input});

    if (!p.first.str.empty()) q.push(p.first);
    if (!p.second.str.empty()) q.push(p.second);
    int res = 0;

    while (!q.empty()) {
      Node curr = q.front();
      q.pop();

      if (curr.str.size() == 1) {
        res += curr.depth;
        continue;
      }

      auto newN  = build(curr);
      if (!newN.first.str.empty()) q.push(newN.first);
      if (!newN.second.str.empty()) q.push(newN.second);
    }

    cout << res << '\n';
  }

  return 0;
}
