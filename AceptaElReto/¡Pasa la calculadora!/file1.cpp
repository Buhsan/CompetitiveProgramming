#include <bits/stdc++.h>

using namespace std;


struct Node {
  int value, prev, turn; //turn: 0 - el q recibe; 1 - el otro jugador
};

map<Node, bool> memo;

map<int, vector<int>> keys = {
  {1, {2, 3, 4, 7}},
  {2, {1, 3, 5, 8}},
  {3, {1, 2, 6, 9}},
  {4, {1, 5, 6, 7}},
  {5, {2, 4, 6, 8}},
  {6, {3, 4, 5, 9}},
  {7, {1, 4, 8, 9}},
  {8, {2, 5, 7, 9}},
  {9, {3, 6, 7, 8}},
};

bool solve(int score, int num) {

  queue<Node> q;
  q.push({score, num, 0});
  bool res = true;

  while(!q.empty()) {
    Node curr = q.front();
    q.pop();
    bool flag = false;

    for (auto v : keys[curr.prev]) {
      int newValue = curr.value + v;
      flag |= (newValue < 31);
    }
    
    if (!flag) {
      res = curr.turn;
      break;
    }

    for (auto v : keys[curr.prev]) {
      int newValue = curr.value + v;
      q.push({newValue, v, 1 - curr.turn});
    }

  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    bool res = (a >= 31 ? true : solve(a,b));
    cout << (res ? "GANA" : "PIERDE") << '\n';
  }


  return 0;
}

