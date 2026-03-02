#include <bits/stdc++.h>

using namespace std;

struct MinQueue {
  deque<int> q;

  void push(int val) {
    while (!q.empty() && q.back() > val) {
      q.pop_back();
    }
    q.push_back(val);
  }

  int min() {return q.front();}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c) {
    queue<pair<int,int>> q;
    queue<int> rest;
    int mini = INT_MAX;
    for (int i = 0; i < c; i++) {
      int a; cin >> a;
      cout << a << " ";
      mini = min(a, mini);
      q.push({a,i});
    }
    cout << '\n';
    char b;
    cout << "print next simbol: " << ((char)cin.peek() == '\n' ? "TRUE" : "FALSE") << endl;
  }
  return 0;
}

