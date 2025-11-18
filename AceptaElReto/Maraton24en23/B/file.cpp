#include <bits/stdc++.h>
using namespace std;

int main() {
  int rows, cols;
  while (cin >> rows >> cols && (rows || cols)) {
    vector<string> start(rows), goal(rows);
    for (int i = 0; i < rows; ++i) cin >> start[i] >> goal[i];

    int total0_start = 0, total1_start = 0, totalR_start = 0;
    int total0_goal = 0, total1_goal = 0;

    map<pair<char, char>, int> mismatch_count;

    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) {
        char s = start[i][j];
        char g = goal[i][j];
        if (s == '0') total0_start++;
        if (s == '1') total1_start++;
        if (s == 'R') totalR_start++;
        if (g == '0') total0_goal++;
        if (g == '1') total1_goal++;

        if (s == g) continue;

        mismatch_count[{s, g}]++;
      }

    if (total1_start + totalR_start < total1_goal ||
        total0_start + total1_start + totalR_start < total0_goal + total1_goal) {
      cout << "IMPOSIBLE\n";
      continue;
    }

    int swaps = 0, restantes = 0;

    for (auto make : mismatch_count) {
      pair<char, char> p = make.first;
      int count = make.second;
      char a = p.first;
      char b = p.second;
      if (a < b && mismatch_count.count({b, a})) {
        int matched = min(count, mismatch_count[{b, a}]);
        swaps += matched;
        mismatch_count[{a, b}] -= matched;
        mismatch_count[{b, a}] -= matched;
      }
    }

    for (auto make : mismatch_count) restantes += make.second;

    int total_op = swaps + restantes;
    cout << total_op << "\n";
  }
  return 0;
}
