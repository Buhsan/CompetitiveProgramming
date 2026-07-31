//WA (not finished)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct Rep {
  int i, j, len
  char c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    char prev = s[0];
    int i = 1;
    vector<Rep> reps;
    while (i < n) {
      if (s[i] == prev) {
        int j = i;
        while (s[j] == prev) {
          prev = s[j];
          j++;
        }
        reps.push_back({i, j, (j-i+1),  s[i]});
        i = j;
      } else {
        prev = s[i];
        i++;
      }
    }

   for (Rep r : reps) {

   }

    cout << "YES\n";
  }


  return 0;
}
