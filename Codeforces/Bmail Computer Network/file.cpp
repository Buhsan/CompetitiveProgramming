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

void dfs(int curr, int limit, vector<bool> &visited, vector<vint> &adj, vint &path) {
  stack<int> q;
  q.push(curr);
  visited[curr] = true;

  while (!q.empty()) {
    int v = q.top();
    q.pop();
    if (v == limit) return;
    REPLIST(i, adj[v]) {
      if (!visited[i]) {
        q.push(i);
        path.push_back(i+1);
        break;
      }
    }
  }
}


void bfs (int curr, int limit, vector<bool> &visited, vector<vint> &adj, vint &prev) {
  queue<int> q;
  q.push(curr);
  visited[curr] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == limit) return;
    REPLIST(i, adj[v]) {
      if (!visited[i]) {
        q.push(i);
        prev[i] = v;
      }
    }
  }
}

void solve(int tt){
  int n; cin >> n;
  vector<vint> adj(n);
  REP(i,1,n) {
    int a; cin >> a; a--;
    // adj[a].push_back(i);
    adj[i].push_back(a);
  }
  vector<bool> visited(n);
  // vint prev(n+1, -1);
  // bfs(0,n-1, visited, adj, prev);
  // int curr = n-1;
  vint path;
  dfs(n-1, 0, visited, adj, path);
  // while (prev[curr] != -1) {
  //   path.push_back(prev[curr] + 1);
  //   curr = prev[curr];
  // }
  reverse(path.begin(), path.end());
  path.push_back(n);
  PRINTLIST(path);
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
