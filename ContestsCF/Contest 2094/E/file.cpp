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


#define TESTCASES 1

void solve(int tt){
  int n, m, k; cin >> n >> m >> k;
  vector<vint> res (n, vint(m,0));
  int num = (n*m)/k;
  // vint cnt (k,num);
  vint values;
  REP(i,0,k){
    REP(j,0,num) {
      values.push_back(i+1);
    }
  }

  int id = 0;

  vector<pair<int, int>> even_cells, odd_cells;
  REP(i,0,n) {
    REP(j,0,m) {
      if ((i+j)%2){
        odd_cells.push_back({i,j});
      }
      else {
        even_cells.push_back({i,j});
      }
    }
  }

  // P(1);

  vector<pair<int, int>> order;
  order.insert(order.end(), even_cells.begin(), even_cells.end());
  order.insert(order.end(), odd_cells.begin(), odd_cells.end());


  REP(id,0,n*m) {
    auto [i,j] = order[id];
    res[i][j] = values[id];
  }

  // REP(i,0,n){
  //   REP(j,0,m){
  //     if (id >= n*m) continue;
  //     if (id <= (n*m)/2) {
  //       if ((i+j) % 2 == 0) {
  //         res[i][j] = values[id];
  //         id++;
  //       }
  //     }
  //     else{
  //         res[i][j] = values[id];
  //         id++;
  //
  //     }
  //   }
  // }

    // PRINTLIST(values);
  // int number = 0;
  // REP(i,0,n) {
  //   if (i%2) {
  //     REP(j,0,m) {
  //       while (cnt[number] == 0){ number = (number+1)%k;}
  //       res[i][j] = number+1;
  //       cnt[number]--;
  //     }
  //   }
  //   else {
  //     REPV(j, m-1, 0) {
  //       while (cnt[number] == 0){ number = (number+1)%k;}
  //       res[i][j] = number+1;
  //       cnt[number]--;
  //     }
  //
  //   }
  // }

  REP(i,0,n){
    PRINTLIST(res[i]);
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
