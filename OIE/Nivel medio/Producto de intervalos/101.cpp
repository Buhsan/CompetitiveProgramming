#include <bits/stdc++.h>

using namespace std;

struct Node {
  int neg, zeros;

  Node operator+(Node a) const {
    return {this->neg + a.neg, this->zeros + a.zeros};
  }
};


struct SegTree {
  vector<Node> tree;
  int n;
  SegTree(vector<Node> &v) {
    n = v.size();
    tree = vector<Node>(n * 4);
    build(1, 0, n-1, v);
  }


  void build(int i, int left, int right, vector<Node> &v) {
    if (left == right) {
      tree[i] = v[left];
      return;
    }

    int leftI = 2*i, rightI = 2*i+1;
    int mid = (right - left) / 2 + left;
    build(leftI, left, mid, v);
    build(rightI, mid+1, right, v);

    tree[i] = tree[leftI] + tree[rightI];
  }


  Node query(int L, int R) {
    return query(1, L, R, 0, n-1);
  }

  Node query(int i, int L, int R, int l, int r) {
    if (L > r || R < l) return {0,0};

    if (L <= l && R >= r) {
      return tree[i];
    }

    int leftI = 2*i, rightI = 2*i+1;
    int mid = (r - l) / 2 + l;
    return query(leftI, L, R, l, mid) + query(rightI, L, R, mid+1, r);
  }


  void update(int idx, int value) {
    update(idx, value, 1, 0, n-1);
  }

  void update(int idx, int value, int i, int left, int right) {
    if (left == right && left == idx) {
      int neg = 0, z = 0;
      if (value < 0) neg++;
      else if (value == 0) z++;
      tree[i] = {neg, z};
      return;
    }

    if (left > idx || idx > right) return;

    int leftI = 2*i, rightI = 2*i+1;
    int mid = (right - left) / 2 + left;
    update(idx, value, leftI, left, mid);
    update(idx, value, rightI, mid+1, right);
    
    tree[i] = tree[leftI] + tree[rightI];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<Node> v(n);
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      int neg = 0, z = 0;
      if (a < 0) neg++;
      else if (a == 0) z++;
      v[i] = {neg, z};
    }

    string s;

    SegTree segi(v) ;
    while (cin >> s) {
      if (s == "FIN") break;
      if (s == "C") {
        int id, val;
        cin >> id >> val;
        segi.update(--id, val);
        //update
      } else {
        int a, b; cin >> a >> b;
        a--, b--;
        Node q = segi.query(a, b);
        if (q.zeros > 0) cout << '0';
        else if (q.neg % 2 == 1) cout << '-';
        else cout << '+';
      }
    }
    cout << endl;

  }

  return 0;
}
