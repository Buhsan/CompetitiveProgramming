#include <bits/stdc++.h>

using namespace std;

struct Register{
  int id, time;
};


struct QueueComparator {
  bool operator()(Register r1, Register r2) {
    int t1 = r1.time;
    int t2 = r2.time; 
    if (t1 != t2) {
      return t1 > t2;
    }
    return r1.id > r2.id;
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c && (n || c)) {
    priority_queue<Register, vector<Register>, QueueComparator> pq;
    for (int i = 1; i <= n; i++) {
      pq.push({i, 0});
    }
    for (int i = 0; i < c; i++) {
      int t; cin >> t;
      Register curr = pq.top();
      pq.pop();
      curr.time += t;
      pq.push(curr);
    }

    cout << pq.top().id << '\n';
  }
  return 0;
}
