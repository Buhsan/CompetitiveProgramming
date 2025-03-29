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
  int c, m, n;
  while (cin >> c >> m >> n){
    int maximo = INT_MIN;
    int minimo = INT_MAX;
    int last = -1;
    int last_cont = -1;
    int current = 0;
    bool res = 1;
    REP(i,0,n+1){
      if(i==0) cin >> last;
      else {
        cin >> current;
        int dif_act = abs(last-current);
        minimo=min(dif_act,minimo);
        maximo = max (dif_act, maximo);
        last = current;
        if (last_cont == -1) last_cont = dif_act;
        else {
          // P(dif_act);
          // P(last_cont);
          // cout << abs(dif_act - last_cont) << endl;
          if (abs(dif_act - last_cont) > c) {res = false;}
          last_cont = dif_act;
        }
      }
    }
    if (res && abs(maximo-minimo) > m){
      res = false;
    }
    cout << (res ? "Ok" : "Tropiezo") << endl;
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
