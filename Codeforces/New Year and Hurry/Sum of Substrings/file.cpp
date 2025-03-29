#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)

#define TESTCASES 1
void solve(int tt){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt_ones = 0;
  int first = n, last = -1;
  REP(i,0,n) {
    if(s[i] == '1') {
      if (first == n) first = i;
      last = i;
      cnt_ones++;
    }
  }

  int coef = 0;
  if (cnt_ones > 0 && (n-1 - last) <= k) {
    k-=(n-1 - last);
    cnt_ones--;
    coef+=1;
  }
  if (cnt_ones > 0 && first <= k) {
    k-=first;
    coef+=10;
    cnt_ones--;
  }

  cout << 11*cnt_ones + coef << endl;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    if (TESTCASES) {
        int tt; cin >> tt;
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
