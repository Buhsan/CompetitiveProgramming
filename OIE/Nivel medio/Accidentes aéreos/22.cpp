#include <bits/stdc++.h>

using namespace std;

struct Accident{
  string date;
  int dead;
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while(cin >> n) {
    vector<Accident> accidents(n);
    for (int i = 0; i < n; i++) cin >> accidents[i].date >> accidents[i].dead;

    stack<Accident> st;
    
    vector<Accident> prevGreater(n, {"NO HAY", -1});
        
    for (int i = 0; i < n; i++) {

      while (!st.empty() && st.top().dead <= accidents[i].dead){
        st.pop();
      }

      if (!st.empty()) {
        prevGreater[i] = st.top();
      }
      st.push(accidents[i]);
    }


    for (int i = 0; i < n; i++) {
      cout << prevGreater[i].date << '\n';
    }

    cout << "---\n";
  }


  return 0;
}
