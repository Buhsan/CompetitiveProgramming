#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_map<string, vector<int>> mapi;
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      string name; cin >> name;

      int a;
      vector<int> aux;
      while (cin >> a && a) aux.push_back(a); 
      sort(aux.begin(), aux.end(), [](const int a, const int b) {return a < b;});
    }

  }

  return 0;
}
