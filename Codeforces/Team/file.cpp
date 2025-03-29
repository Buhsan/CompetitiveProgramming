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

#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define PRINT(v) cout << v << endl
#define P(v) cout << #v << ": " << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

const ll MOD = 1e9 + 7;


#define TESTCASES 0

void solve(int tt){
  int ones, zeros; cin >> zeros >> ones;
  // P(zeros);
  // P(ones);
  // cout << abs((ones/2) - zeros) << endl;
  if (zeros-ones< -1 && abs((ones/2 + ones%2)) > zeros+1){
    cout << -1 << endl;
  }
  else{
    int pairs = ones/2;
    int solos = ones%2;
    if ((ones/2 + ones%2) < zeros) {
      pairs--, solos+=2;
    }
    // P(pairs);
    // P(solos); 
    // P(zeros);
    string p = "11", s = "1", z="0";
    int length = zeros + (ones == 1 ? 1 : pairs+solos);
    int type = ones >= zeros;
    string res = "";
    REP(i,0,length) {
      // cout << pairs << " " << solos << " " << zeros << endl;
      if (type){
        if (pairs > 0) res+=p, pairs--;
        else if (solos > 0) res+=s, solos--;
        type = 1 - type;
      }
      else{
        if (zeros > 0) {
          res += z;
          zeros--;
          type = 1 - type;
        }
      }
    }
    cout << res << endl;
  }
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
