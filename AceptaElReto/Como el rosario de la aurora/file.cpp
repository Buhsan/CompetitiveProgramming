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

void dfs(vector<vint> &adj, int current, vector<bool> &visited, int &g1, int &g2, bool flag) {
  if (flag) g1++;
  else g2++;

  for(int i : adj[current]) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(adj, i, visited, g1, g2, !flag);
    }
  }
}



void solve(int tt){
  int n, p, a;
  while (cin >> n >> p >> a) {
    vector<vint> adj(n);
    REP(i,0,p) {
      int a, b;
      cin >> a >> b; a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vint amigos, enemigos;
    vector<bool> visited(n);
    REP(i,0,n){
      if (!visited[i]) {
        visited[i] = true;
        int g1 = 0, g2 = 0;
        dfs(adj, i, visited, g1, g2, true);
        if (g2 == 0) g2 = g1;
        amigos.push_back(g1);
        enemigos.push_back(g2);
      }
    }
    vector<vint> dp(amigos.size() + 1, vint(a + 1, 0));
    for (int i = 1; i < amigos.size() + 1; i++) {
      for (int j = 1; j < a + 1; j++) {
        dp[i][j] = dp[i - 1][j];

        if (j >= amigos[i - 1]) dp[i][j] = max(dp[i][j], amigos[i - 1] + dp[i - 1][j - amigos[i - 1]]);
        if (j >= enemigos[i - 1]) dp[i][j] = max(dp[i][j], enemigos[i - 1] + dp[i - 1][j - enemigos[i - 1]]);
      }
    }
    cout << dp[amigos.size()][a] << endl;
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
