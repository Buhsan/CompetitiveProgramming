#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define PLIST(list) cout << #list << ": "; for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

// #define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
// #define PRINT(...) ((cout << ... << " "), cout << endl)
#define PRINT(v) cout << v << endl;
#define P(v) cout << #v << ": " << v << endl;


#define TESTCASES 0

void solve(int tt){
  map<char, int> previous;
  map<char, int> next;
  string s; cin >> s;
  REPLIST(i,s) {
    previous[i]++;
  }

  string s1; cin >> s1;
  REPLIST(j,s1) {
    previous[j]++;
  }

  string s2; cin >> s2;
  REPLIST(k,s2) {
    next[k]++;
  }
  cout << (previous == next ? "YES" : "NO");
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
