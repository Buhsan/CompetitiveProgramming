#include <bits/stdc++.h>

using namespace std;

unordered_map<char, vector<string>> dic;

vector<string> getAnagram(string phrase) {
  vector<string> res;
  cout << "phrase: " << phrase << endl;
  int n = phrase.size();
  unordered_set<string> words;
  for (int i = 0; i < n; i++) {
    if (phrase[i] == ' ') continue;
    for (string w : dic[phrase[i]]) {
      words.insert(w);
    }
  }
  cout << "possible words: " << words.size();
  for (string s : words) {
    cout << " " << s;
  }
  cout << endl;

  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s && s != "#") {
    cout << s << endl;
    for (int i = 0; i < s.size(); i++) {
      dic[s[i]].push_back(s);
    }
  }

  vector<string> phrases;
  string phrase;

  cin.ignore();
  cout << endl;
  cout << endl;
  while (getline(cin, phrase) && phrase != "#") {
    phrases.push_back(phrase);
  }


  for (int i = 0; i < phrases.size(); i++) {
    getAnagram(phrases[i]);
  }

  return 0;
}
