#include <bits/stdc++.h>

using namespace std; 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    vector<int> result(n, -1);
    stack<int> st;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
      cin >> heights[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && st.top() < heights[i]) {
        st.pop();
      }

      if (!st.empty()) result[i] = st.top();

      st.push(heights[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (result[i] == -1);
    }
    cout << ans << '\n';
  }

  return 0;
}
