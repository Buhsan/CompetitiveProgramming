#include <bits/stdc++.h>

using namespace std;

int max_size = 1;
int max_count = 0;

template <typename T> void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template <typename T> int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v])
    return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template <typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    max_count--;
    if (size[a] < size[b])
      swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
    max_size = max({size[a], size[b], max_size});
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  max_count = n;
  vector<int> dsu(n), size(n);

  for (int i = 0; i < n; i++) {
    make_set(dsu, size, i);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b, a--, b--;
    union_sets(dsu, size, a, b);
    cout << max_count << " " << max_size << endl;
  }
  return 0;
}
