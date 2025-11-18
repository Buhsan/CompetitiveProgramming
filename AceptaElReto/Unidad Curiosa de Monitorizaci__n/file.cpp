#include <bits/stdc++.h>

using namespace std;


struct Node {
  int id, i, time;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    priority_queue<Node, vector<Node>, function<bool(const Node &, const Node &)>> pq ([](const Node &a, const Node &b) {return (a.time == b.time) ? a.id > b.id : a.time > b.time;});
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      pq.push({a, b, b});
    }

    int cnt = 0;
    int t; cin >> t;
    while(cnt < t) {
      Node p = pq.top();
      pq.pop();
      cout << p.id <<'\n';
      pq.push({p.id, p.i, p.time + p.i});
      cnt++;
    }
    cout << "----" << '\n';
  }

  return 0;
}
