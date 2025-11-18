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


struct Node {
  ll node;
  ll weight;

};

void solve(int tt){
  ll n,m; cin >> n >> m;
  vector<vector<pll>> adj(n);
  REP(i,0,m) {
    ll a, b, w; cin >> a >> b >> w; 
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
  }
  vll dist(n, LLONG_MAX);
  priority_queue<Node, vector<Node>, function<bool (Node, Node)>> pq([] (const Node &x, const Node &y){
      return x.weight > y.weight;
      });

  dist[0] = 0;
  pq.push({0,0});
  while (!pq.empty()) {
    Node vertex = pq.top();
    ll node = vertex.node;
    ll curr_dist = vertex.weight;
    pq.pop();

    if (curr_dist > dist[node]) continue;

    for (auto [v, weight] : adj[node]) {
      if (dist[node] + weight < dist[v]) {
        dist[v] = dist[node] + weight;
        pq.push({v, dist[v]});
      }
    }
  }

  cout << dist[n-1] << endl;


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
