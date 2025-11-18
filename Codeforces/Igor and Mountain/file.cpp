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

const ll MOD = 998244353;


#define TESTCASES 1

int dist(pii a, pii b) {
  return (a.first - b.first)*(a.first-b.first) + (a.second - b.second)*(a.second-b.second);
}

struct Node {
  int i, j, hands;
};

void solve(int tt){
  int n, m, d; cin >> n >> m >> d;
  vector<vector<pii>> holds(n);
  REP(i,0,n) {
    string s; cin >> s;
    REP(j,0,m) {
      if (s[j] == 'X') {
        holds[i].push_back({i,j});
      }
    }
  }

  queue<Node> q;
  vector<vint> ways(n, vint(n,1));
  // P(1);
  // PPAIR(holds[n-1]);

  REP(i,0,holds[n-1].size()) {
    ways[n-1][i] = 1;
    q.push({n-1, i, 1});
  }
  while(!q.empty()) {
    auto [i, j, hand] = q.front();
    pii pos_init = holds[i][j];
    q.pop();


    int cuurrWays = ways[i][j];

    if (i == 0) continue;
    
    REP(k,0,holds[i-1].size()) {
      pii pos = holds[i-1][k];
      if (dist(pos_init, pos) <= d*d) {
        if (ways[i-1][k] == 0) {
          q.push({i-1, k, 1});
        }
        ways[i-1][k] = (ways[i-1][k] + cuurrWays) % MOD;
      }
    }
    if (hand == 1) {
      REP(k,0,holds[i-1].size()) {
        if (k == j) continue;
        pii pos1 = holds[i-1][k];
        if (dist(pos_init, pos1) <= d*d) {
          if (ways[i-1][k] == 0) {
            q.push({i-1, k, 1});
          }
          ways[i-1][k] = (ways[i-1][k] + cuurrWays) % MOD;
        }
      }
    }
  }

  int res = 0;
  REP(i,0,n) {
    res = (res + ways[0][i])%MOD;
  }
  cout << res << endl;
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
