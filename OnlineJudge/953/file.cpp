#include <bits/stdc++.h>

using namespace std;
struct Pile {
  vector<int> types;
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<Pile> piles;
    vector<int> totals(n);
    for (int j = 0; j < n; j++) {
      Pile aux;
      for (int i = 0; i < n; i++) {
        int a; cin >> a;
        totals[i]+=a;
        aux.types.push_back(a);
      }
      piles.push_back(aux);
    }

    vector<int> ids(n);
    string bestConfig = "";
    int bestScore = INT_MAX;
    for (int i = 0; i < n; i++) ids[i] = i;
    do {
      int score = 0;
      for (int i = 0; i < n; i++) {
        score += (totals[ids[i]] - piles[i].types[ids[i]]);
      }
      string currConfig = "";
      for (int i = 0; i < n; i++) {
        currConfig += to_string(ids[i]);
      }
      if (score < bestScore) {
        bestScore = score;
        bestConfig = currConfig;
      } else if (score == bestScore && currConfig < bestConfig) {
        bestConfig = currConfig;
      }
    } while (next_permutation(ids.begin(), ids.end()));

    cout << bestConfig << " " << bestScore << endl;
  }
  return 0;
}
