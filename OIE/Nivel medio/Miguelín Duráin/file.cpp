#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll countMerge(vector<ll> &v, int left, int mid, int right) {
  int n1, n2;
  n1 = mid - left + 1;
  n2 = right - mid;
  vector<ll> leftPart(n1), rightPart(n2);
  for (int i = 0; i < n1; i++) {
    leftPart[i] = v[left + i];
  }
  for (int i = 0; i < n2; i++) {
    rightPart[i] = v[mid + i + 1];
  }

  ll res = 0;
  int i = 0, j = 0, k = left; // i - left, j - right, k - true idx of elem
  while (i < n1 && j < n2) {
    if (leftPart[i] <= rightPart[j]) { // no inversion
      v[k++] = leftPart[i++];
    } else {
      v[k++] = rightPart[j++];
      res += (n1 - i);
    }
  }
  while (i < n1) {
    v[k++] = leftPart[i++];
  }
  while (j < n2) {
    v[k++] = rightPart[j++];
  }
  return res;
}

ll countInv(vector<ll> &v, int left, int right) {
  ll res = 0;
  if (left < right) {
    int mid = (right - left) / 2 + left;
    res += countInv(v, left, mid);
    res += countInv(v, mid + 1, right);
    res += countMerge(v, left, mid, right);
  }
  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  while (cin >> n >> x && (n || x)) {
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += x*i;
    }
    int n = a.size();
    cout << (ll)countInv(a, 0, n-1) << '\n';
  }
  return 0;
}
