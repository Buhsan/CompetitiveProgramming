#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  string pattern;

  while(cin >> n >> m >> pattern) {
    string linePattern = "";
    int reps = m / pattern.size();
    int rest = m % pattern.size();
    for (int i = 0; i < reps; i++) {
      linePattern += pattern;
    }

    for (int i = 0; i < rest; i++) {
      linePattern += pattern[i];
    }


    int idToPush = pattern.size() - 1;
    for (int i = 0; i < n; i++) {
      cout << linePattern << '\n';

      linePattern.pop_back();

      linePattern = string(1, pattern[idToPush]) + linePattern;
      idToPush--;
      idToPush = (idToPush + pattern.size()) % pattern.size();
    }
  }


  return 0;
}
