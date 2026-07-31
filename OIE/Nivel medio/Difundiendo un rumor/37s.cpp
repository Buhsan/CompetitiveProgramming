#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> parent, size, mini;

  DSU (int n, vector<int> &m) {
    parent = vector<int>(n);
    size = vector<int>(n);
    mini = vector<int>(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
      mini[i] = m[i];
    }
  }

  int find (int x) {
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
    int newMini = min(mini[a], mini[b]);
    mini[a] = newMini;
    mini[b] = newMini;
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<int> money(n);
    for (int i = 0; i < n; i++) cin >> money[i];
    DSU dsu(n, money);
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      //cout << u << " " << v << endl;
      u--, v--;
      dsu.merge(u,v);
      /*cout << "parent: ";
      for (int i = 0; i < n; i++) {
        cout << dsu.parent[i] << " ";
      }
      cout << endl;*/
    }
    /*cout << endl;
    cout << endl;
    cout << endl;

    cout << "money: ";
    for (int i = 0; i < n; i++) {
      cout << money[i] << " ";
    }
    cout << endl;

    cout << "parent: ";
    for (int i = 0; i < n; i++) {
      cout << i+1 << " ";
    }
    cout << endl;

    cout << "parent: ";
    for (int i = 0; i < n; i++) {
      cout << dsu.parent[i] << " ";
    }
    cout << endl;

    cout << "mini: ";
    for (int i = 0; i < n; i++) {
      cout << dsu.mini[i] << " ";
    }
    cout << endl;*/


    unordered_set<int> visited;
    for (int i = 0; i < n; i++) {
      visited.insert(dsu.find(i));
    }
    long long res = 0;
    for (int v : visited) {
      res += dsu.mini[v];
    }

    cout << res << '\n';
  }

  return 0;
}
