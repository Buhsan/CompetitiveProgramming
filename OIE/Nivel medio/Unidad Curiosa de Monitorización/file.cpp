#include <bits/stdc++.h>

using namespace std;


struct User {
  int id, time;
  int currTime;
};


struct UserComparator{
  bool operator()(User u1, User u2) {
    if (u1.currTime != u2.currTime) {
      return u1.currTime > u2.currTime;
    }
    return u1.id > u2.id;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    priority_queue<User, vector<User>, UserComparator> pq;
    for (int i = 0; i < n; i++) {
      int id; cin >> id;
      int time; cin >> time;
      pq.push({id, time, time});
    }
    int k; cin >> k;

    for (int i = 0; i < k; i++) {
      User curr = pq.top();
      pq.pop();
      cout << curr.id << '\n';
      pq.push({curr.id, curr.time, curr.currTime + curr.time});
    }
    cout << "---\n";
  }



  return 0;
}
