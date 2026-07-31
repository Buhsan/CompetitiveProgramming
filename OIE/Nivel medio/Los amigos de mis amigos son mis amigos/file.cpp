#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> parent, size;
  int maxSize;

  DSU(int n) {
    parent = vector<int>(n);
    size = vector<int>(n);
    maxSize = 1;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
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
    size[a] += size[b];
    maxSize = max(size[a], maxSize);
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      u--, v--;
      dsu.merge(u,v);
    }

    cout << dsu.maxSize << '\n';
  }

  return 0;
}

