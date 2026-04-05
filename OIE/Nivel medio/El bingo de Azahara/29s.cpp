#include <bits/stdc++.h>

using namespace std;


struct Player {
  string name;
  unordered_set<int> cards;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    unordered_map<int,vector<Player*>> numbers;
    vector<Player> players(n);
    vector<string> winners;
    for (int i = 0; i < n; i++) {
      cin >> players[i].name;
      int a;
      while (cin >> a && a) {
        numbers[a].push_back(&players[i]);
        players[i].cards.insert(a);
      }
    }

    int m; cin >> m;
    vector<int> values(m);
    for (int i = 0; i < m; i++) cin >> values[i];
    bool finish = false;
    int i = 0;
    while (i < m && !finish) {
      int num = values[i];
      for (Player* &pl : numbers[num]) {
        pl->cards.erase(num);
        if (pl->cards.empty()) {
          winners.push_back(pl->name);
          finish = true;
        }
      }
      i++;
    }

    sort(winners.begin(), winners.end());
    if (winners.empty()) {
      cout << '\n';
    } else {
      cout << winners[0];
      for (int i = 1; i < winners.size(); i++) {
        cout << " " << winners[i];
      }
      cout << '\n';
    }
  }
  return 0;
}
