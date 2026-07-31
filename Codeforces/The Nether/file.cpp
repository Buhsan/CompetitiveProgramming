#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string nums = "";
    map<int,vector<int>> p;
    for (int i = 1; i <= n; i++) {
      nums+=" ";
      nums+=to_string(i);
    }

    int maxi = -1;
    for (int i = 1; i <= n; i++) {
      cout << "? " << i << " " << n << nums << endl;
      int a; cin >> a;
      maxi = max(maxi, a);
      p[a].push_back(i);
    }
    /*for (auto pa : p) {
      cout << pa.first << ":";
      for (int j : pa.second) {
        cout << " " << j;
      }
      cout << endl;
      
    }*/
    vector<int> res;
    int prev = p[maxi][0];
    res.push_back(prev);
    for (int i = 1; i <= maxi-1; i++) {
      //cout << "prev: " << prev << endl;
      vector<int> v = p[maxi-i];
      if (v.size() == 1) {
        res.push_back(v[0]);
        prev = v[0];
      } else {
        for (int j : v) {
          cout << "? " << prev << " 2 "<< j << " " << prev << endl;
          int a; cin >> a;
          if (a > 1) {
            prev = j;
            res.push_back(prev);
            break;
          }
        }
      }
    }
    cout << "! " << res.size();
    for (int i = 0; i < res.size(); i++) {
      cout << " " << res[i];
    }
    cout << endl;
  }

  return 0;
}
