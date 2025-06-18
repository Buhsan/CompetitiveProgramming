#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, s, e;
  while (cin >> n >> k >> s >> e && (n || k || s || e)) {
    vector<int> adj(n * n, -1);
    for (int i = 0; i < s + e; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a] = b;
    }

    queue<int> q;
    vector<int> min_dist(n * n, INT_MAX);
    q.push(0);
    min_dist[0] = 0;

    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      if (curr == n * n - 1) {
        break;
      }
      for (int i = 1; i <= k; i++) {
        int newCurr = curr + i;
        if (newCurr > n * n - 1)
          break;
        if (adj[newCurr] != -1)
          newCurr = adj[newCurr];

        if (min_dist[curr] + 1 < min_dist[newCurr]) {
          min_dist[newCurr] = min_dist[curr] + 1;
          q.push(newCurr);
        }
      }
    }
    cout << min_dist[n * n - 1] << endl;
  }

  return 0;
}
