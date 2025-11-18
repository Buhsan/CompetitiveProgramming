#include <bits/stdc++.h>

using namespace std;

void run (string &num, int i, int rest) {
    if (num == "9") {
      num[i] = 'F';
    } else if (num == "F") {
      rest++;
      num[i] = '0';
    }
    else {
      num[i]++;
    }
  if (rest != 0 && i > 0) {
    run (num, --i, rest);
  }
} 

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string num;

  while (cin >> num && num != "FIN") {
    int i = num.size() - 1;
    run(num, i, 0);
    cout << num << '\n';
  }

  



  return 0;
}
