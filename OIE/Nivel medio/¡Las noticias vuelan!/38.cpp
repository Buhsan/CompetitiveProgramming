#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> parent, size;

  DSU (int n) {
    parent = vector<int>(n);
    size = vector<int>(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i; size[i] = 1;
    }
  }

  int find(int x) {
    if (parent[x] == x) return parent[x];
    return parent[x] = find(parent[x]);
  }

  void merge(int u, int v) {
    int a = find(u);
    int b = find(v);

    if (a == b) return;

      if (size[b] > size[a]) swap(a,b);
    parent[b] = a;
    size[a]+=size[b];
  }
};



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
      int k; cin >> k;
      int prev = -1;
      for (int j = 0; j < k; j++) {
        int u; cin >> u; u--;
        if (prev != -1) dsu.merge(u, prev);
        prev = u;
      }
    }

    cout << dsu.size[dsu.find(0)];
    for (int i = 1; i < n; i++) {
      cout << ' ' << dsu.size[dsu.find(i)];
    }
    cout << '\n';
  }



  return 0;
}
