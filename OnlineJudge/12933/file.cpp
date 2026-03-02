#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  while (cin >> n >> m) {
    pair<int,int> start,end;
    int a,b; cin >> a >> b;
    int c,d; cin >> c >> d;
    start = {a-1, b-1};
    end = {c-1, d-1};
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
      string s; cin >> s;
      grid.push_back(s);
    }
  }

  return 0;
}
