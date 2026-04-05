#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> in(n);
    unordered_map<int,int> id;
    for (int i = 0; i < n; i++) {
      cin >> in[i];
      id[in[i]] = i;
    }
    
    vector<int> nextGreater(n,-1);
    vector<int> nextSmaller(n,-1);
    
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
      while(!st.empty() && in[i] > st.top()) {
        st.pop();
      }

      if (!st.empty()) {
        nextGreater[i] = st.top();
      }
      st.push(in[i]);
    }

    stack<int> st1;
    for (int i = n-1; i >= 0; i--) {
      while(!st1.empty() && in[i] < st1.top()) {
        st1.pop();
      }

      if (!st1.empty()) {
        nextSmaller[i] = st1.top();
      }
      st1.push(in[i]);
    }

    bool res = true;

    for (int i = 0; i < n; i++) {
      if (nextGreater[i] != -1 && nextSmaller[id[nextGreater[i]]] != -1) {
        res = false;
        break;
      }
    }

    cout << (res ? "SIEMPRE PREMIO" : "ELEGIR OTRA") << '\n';

  }

  

  return 0;
}
