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

int bfs (int curr, vector<bool> &visited, vector<vint> &adj) {
  queue<pii> q;
  int cnt = 0;
  visited[curr] = true;
  q.push({curr, 1});
  while (!q.empty()) {
    pii v = q.front();
    q.pop();
    int node = v.first;
    int high = v.second;

    REPLIST(i, adj[node]) {
      // cout << "vecinos: " << i << endl;
      if (!visited[i]) {
        visited[node] = true;
        q.push({i, high+1});
      }
    }
    if (q.empty()) {cnt = high;}
  }
  return cnt;
}

void solve(int tt){
  int n; cin >> n;
  vector<vint> adj(n);
  vint neg;
  REP(i,0,n){
    int a; cin >> a;
    if (a == -1) {neg.push_back(i); continue;}
    a--;
    adj[a].push_back(i);
  }
  int res = 1;
  REPLIST(i, neg){
    if (adj[i].size() > 0) {
      vector<bool> visited(n);
      int b = bfs(i, visited, adj);
      if (b == 0) continue;
      res = max(res, b);
    }
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
