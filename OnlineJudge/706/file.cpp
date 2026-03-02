#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> digits = {
{1,1,1,0,1,1,1},//0
{0,0,1,0,0,1,0},//1
{1,0,1,1,1,0,1},//2
{1,0,1,1,0,1,1},//3
{0,1,1,1,0,1,0},//4
{1,1,0,1,0,1,1},//5
{1,1,0,1,1,1,1},//6
{1,0,1,0,0,1,0},//7
{1,1,1,1,1,1,1},//8
{1,1,1,1,0,1,1},//9
};

vector<vector<char>> create(int dig, int s){
  int n = 2 * s + 3;
  int m = s + 2;
  vector<vector<char>> digit(n, vector<char>(m, ' '));
  for(int i = 0; i <= 6; i++) {
    if (digits[dig][i]) {
      if (i == 0) {
        for (int i = 1; i <= s; i++) {
          digit[0][i] = '-';
        }
      } else if (i == 1) {
        for (int i = 1; i <= s; i++) {
          digit[i][0] = '|';
        }
      } else if (i == 2) {
        for (int i = 1; i <= s; i++) {
          digit[i][m-1] = '|';
        }
      } else if (i == 3) {
        for (int i = 1; i <= s; i++) {
          digit[m-1][i] = '-';
        }
      } else if (i == 4) {
        for (int i = s+2; i < n-1; i++) {
          digit[i][0] = '|';
        }
      } else if (i == 5) {
        for (int i = s+2; i < n-1; i++) {
          digit[i][m-1] = '|';
        }
      } else if (i == 6) {
        for (int i = 1; i <= s; i++) {
          digit[n-1][i] = '-';
        }
      }
    }
  }
  return digit;
}

void print(const vector<vector<vector<char>>> &digit) {
  int n = digit[0].size();
  int m = digit[0][0].size();
  int t = digit.size();
  // cout << "n: " << n << " m: " << m << " t: " << t << endl;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < t; k++) {
      for (int j = 0; j < digit[k][i].size(); j++) {
        cout << digit[k][i][j];
      }
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  // int t = 0;
  // vector<vector<char>> sep(2*2+3, vector<char>(1,' ')); 
  // for (int i = 0; i < 2*2+3; i++) {
  //   cout << sep[i][0] << endl;
  // }
  while (cin >> n >> s && n) {
    vector<vector<vector<char>>> res;
    vector<vector<char>> aux;
    // if (t) cout << '\n';
    res.push_back(create((s[0]-'0'), n));
    vector<vector<char>> sep(2*n+3, vector<char>(1,' ')); 
    for (int i = 1; i < s.size(); i++) {
      res.push_back(sep);
      res.push_back(create((s[i]-'0'), n));
    }
    print(res);
    cout << '\n';
    // t++;
  }
  return 0;
}
