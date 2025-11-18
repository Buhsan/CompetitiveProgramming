#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int getMinHeight(int n) {
  if (n == 0) return 0;
  int h = 0;
  while ((1 << h) - 1 < n) h++;
  return h;
}

bool build(int lo, int hi, int h) {
  if (lo > hi) return true;
  if (h == 0) return false;

  int size = hi - lo + 1;

  if (getMinHeight(size) > h) return false;

  for (int root = lo; root <= hi; root++) {
    int left = root - lo;
    int right = hi - root;

    if (getMinHeight(left) <= h - 1 && getMinHeight(right) <= h - 1) {
      res.push_back(root);

      if (!build(lo, root - 1, h - 1)) return false;
      if (!build(root + 1, hi, h - 1)) return false;
      return true;
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    res.clear();

    if (!build(1, n, k)) {
      cout << "IMPOSIBLE\n";
    } else {
      for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << ' ';
        cout << res[i];
      }
      cout << '\n';
    }
  }

  return 0;
}
