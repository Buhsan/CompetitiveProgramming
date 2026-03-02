#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  string temp;
  getline(cin,temp);
  getline(cin,temp);
  for (int tt = 0; tt < t; tt++) {
    vector<string> input;
    string s;
    unordered_map<int, int> reg, ram;
    for (int i = 0; i <= 9; i++) {
      reg[i] = 0;
    }
    for (int i = 0; i <= 999; i++) {
      ram[i] = 0;
    }
    int id = 0;
    while (getline(cin, s) && !s.empty()) {
      // cout << "s: " << s << endl;
      int n = stoi(s);
      ram[id] = n;
      id++;
    }
    int res = 0;
    int cursor = 0;
    while (true) {
      // cout << "cursor at: " << cursor << endl;
      res++;
      int first = ram[cursor] / 100;
      int second = (ram[cursor] / 10) % 10;
      int third = ram[cursor] % 10;
      // cout << "command: " << first << " " << second << " " << third << endl;
      if (ram[cursor] == 100) {
        break;
      }
      if (first == 2) {
        // cout << "entring 2: ";
        reg[second] = (third % MOD);
        // cout << "reg" << second << " = " << third << endl;
        cursor++;
      } else if (first == 3) {
        // cout << "entring 3: ";
        reg[second] = (reg[second] + third) % MOD;
        // cout << "reg" << second << " = reg" << second << " + " << third << "
        // = " << reg[second] << endl;;
        cursor++;
      } else if (first == 4) {
        // cout << "entering 4: ";
        reg[second] = (reg[second] * third) % MOD;
        // cout << "reg" << second << " = reg" << second << " * " << third << "
        // = " << reg[second] << endl;;
        cursor++;
      } else if (first == 5) {
        // cout << "entering 5: ";
        reg[second] = reg[third];
        // cout << "reg" << second << " = reg" << third << " = " <<
        // reg[second]<< endl;
        cursor++;
      } else if (first == 6) {
        // cout << "entering 6: ";
        reg[second] = (reg[second] + reg[third]) % MOD;
        // cout << "reg" << second << " = reg" << second << " + reg" << third <<
        // " = " << reg[second] << endl;
        cursor++;
      } else if (first == 7) {
        // cout << "entering 7: ";
        reg[second] = (reg[second] * reg[third]) % MOD;
        // cout << "reg" << second << " = reg" << second << " * reg" << third <<
        // " = " << reg[second] << endl;
        cursor++;
      } else if (first == 8) {
        // cout << "entering 8: ";
        reg[second] = ram[reg[third]];
        // cout << "reg" << second << " = ram" << reg[third] << " = " <<
        // ram[reg[third]] << endl;;
        cursor++;
      } else if (first == 9) {
        // cout << "entering 9: ";
        ram[reg[third]] = reg[second];
        // cout << "ram" << reg[third] << " = reg" << second << " = " <<
        // ram[reg[third]] << endl;
        cursor++;
      } else if (first == 0) {
        if (reg[third] != 0) {
          // cout << "entering 0: ";
          cursor = reg[second];
          // cout << "cursor goes to: reg" << second << " = " << reg[second] <<
          // endl;
        } else {
          cursor++;
        }
      }
      // res++;
      // cout << endl;
    }
    if (tt > 0) cout << '\n';
    cout << res << '\n';
    // cout << res << "\n\n";
    // if (tt == 0) {
    //   cout << res;
    // } else {
    //   cout << "\n\n" << res;
    // }
  }
  return 0;
}
