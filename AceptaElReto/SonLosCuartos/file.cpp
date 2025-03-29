#include <bits/stdc++.h>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)

#define TESTCASES 1

void solve(int tt){
  string s;
  getline(cin,s);
  short int n = s.size();
  cout << (n == 0 ? "MARISA NARANJO" : n > 71 ? "SALIDA NULA" : n < 71 ? "TARDE" : "CORRECTO") << endl;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    if (TESTCASES) {
        int tt; cin >> tt;
    cin.ignore();
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
