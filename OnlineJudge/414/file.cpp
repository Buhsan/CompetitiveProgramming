#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<int> diffs;
    int bestDiff = INT_MAX;
    cin.ignore();

    for (int i = 0; i < n; i++) {
      string s; getline(cin, s);

      int left = 0;
      int right = 0;
      int j = 0;
      while (j < s.size() && s[j] != ' ') left++, j++;
      j = s.size()-1;
      while (j >= 0 && s[j] != ' ') right++, j--;
      int currDiff = 25 - (left+right);
      //cout << "left: " << left << " right: " << right  << " diff: " << currDiff << endl;
      if (currDiff < 0) currDiff = 0;
      diffs.push_back(currDiff);
      bestDiff = min(currDiff, bestDiff);
    }
    int res = 0;
    //cout << "bestDiff: " << bestDiff <<  endl;
    //if (bestDiff < 0 || bestDiff == INT_MAX) bestDiff = 25;
    for (int num : diffs) {
      //cout << "diff: " << num << endl;
      res += abs(num - bestDiff);
    }

    cout << res << '\n';
  }

  return 0;
}
