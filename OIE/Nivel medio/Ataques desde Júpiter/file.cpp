
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct SegTree {
  vector<ll> tree;
  int n;
  int MOD;

  SegTree(vector<ll> &v, int mod) {
    n = v.size();
    tree = vector<ll>(4*n);
    MOD = mod;
    build(1, 0, n-1, v);
  }

  void build(int i, int l, int r, vector<ll> &v) {
    if (l == r) {
      tree[i] = v[l];
      return;
    }

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    build(li, l, mid, v);
    build(ri, mid+1, r, v);

    tree[i] = (tree[li] + tree[ri]) % MOD;
  }


  ll query(int L, int R) {
    return query(1, L, R, 0, n-1);
  }

  ll query(int i, int L, int R, int l, int r) {
    if (L > r || R < l) return 0; 

    if (L <= l && r <= R) return tree[i];

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    return (query(li, L, R, l, mid) + query(ri, L, R, mid+1, r)) % MOD;
  }

  void update(int idx, ll value) {
    return update(idx, value, 1, 0, n-1);
  }


  void update(int idx, ll value, int i, int l, int r) {
    if (l == r && l == idx) {
      tree[i] = value;
      return;
    }

    if (l > idx || idx > r) return;

    int li = 2*i, ri = 2*i+1;
    int mid = (r - l) / 2 + l;

    update(idx, value, li, l, mid);
    update(idx, value, ri, mid+1, r);

    tree[i] = (tree[li] + tree[ri]) % MOD;
  }

};

int inv(int a, int m) {
  return a <= 1 ? a : m - (ll)(m/a) * inv(m % a, m) % m;
}

ll fastpow(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = (res * a) % mod; 
    a = (a*a) % mod;
    b /= 2;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int b, p, n;
  while (cin >> b >> p >> n) {
    vector<ll> v(n);

    SegTree segi(v, p);
    string s;
    while (cin >> s) {
      if (s == "FIN") break;

      if (s == "E") {
        int idx, val;
        cin >> idx >> val;
        idx--;
        ll updateValue = ((ll)val * fastpow(b, (n-1) - idx, p)) % p;
        //cout << "updateValue: " << updateValue << endl;
        segi.update(idx, updateValue);
      } else {
        int left, right;
        cin >> left >> right;
        ll q = segi.query(--left, --right);
        int shift = n - 1 - right;
        cout << "shift: " << shift << endl;
        cout << "query: " << q << endl;
        ll num = inv(fastpow(b, shift, p), p);
        ll res = (q%p * inv(fastpow(b, left, p), p)) % p;
        cout << ((q%p) * (num%p)) % p<< endl;
      }
    }
    cout << "---\n";
  }

  return 0;
}
