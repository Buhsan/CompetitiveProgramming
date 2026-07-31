#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  vector<int> tree;
  int n;

  SegTree(vector<int> &v) {
    n = v.size();
    tree = vector<int>(4*n);
    build(1, 0, n-1, v);
  }

  void build(int i, int l, int r, vector<int> &v) {
    if (l == r) {
      tree[i] = v[l];
      return;
    }

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    build(li, l, mid, v);
    build(ri, mid+1, r, v);

    tree[i] = tree[li] + tree[ri];
  }


  int query(int L, int R) {
    return query(1, L, R, 0, n-1);
  }

  int query(int i, int L, int R, int l, int r) {
    if (L > r || R < l) return 0; 

    if (L <= l && r <= R) return tree[i];

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    return query(li, L, R, l, mid) + query(ri, L, R, mid+1, r);
  }

  void update(int idx, int value) {
    return update(idx, value, 1, 0, n-1);
  }


  void update(int idx, int value, int i, int l, int r) {
    if (l == r && l == idx) {
      tree[i] = value;
      return;
    }

    if (l > idx || idx > r) return;

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    update(idx, value, li, l, mid);
    update(idx, value, ri, mid+1, r);

    tree[i] = tree[li] + tree[ri];
  }

};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    

    SegTree segi(v);
    string s;
    while (cin >> s) {
      if (s == "FIN") break;

      if (s == "S") {
        int idx, val;
        cin >> idx >> val;
        segi.update(--idx, val);
      } else {
        int a, b;
        cin >> a >> b;
        cout << segi.query(--a, --b) << '\n';
      }
    }
    cout << "---\n";
  }


  return 0;
}
