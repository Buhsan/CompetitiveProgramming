#include <bits/stdc++.h>
using namespace std;

string check(string sample, vector<string> pull) {
  vector<string> result;
  int n = pull.size();
  string s = sample;
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++) {
    string aux = pull[i];
    string aux1 = pull[i];
    sort(aux1.begin(), aux1.end());
    if ((sample[0] == aux[0] &&
         sample[sample.size() - 1] == aux[aux.size() - 1]) &&
        (s == aux1))
      result.push_back(pull[i]);
  }
  if (result.size() == 1)
    return result[0];
  return "";
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    unordered_map<int, vector<string>> dic;
    string s;
    while (cin >> s && s != ".") {
      dic[s.size()].push_back(s);
    }

    while (cin >> s && s != ".") {
      string aux = check(s, dic[s.size()]);
      if (aux.empty()) {
        cout << s << " ";
      } else
        cout << aux << " ";
    }
    cout << "." << endl;
  }
  return 0;
}
