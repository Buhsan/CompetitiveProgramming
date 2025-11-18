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

vector<pii> directions = {{1,0}, {-1, 0}, {0, 1}, {0, -1}, {1,1}, {1, -1}, {-1, -1}, {-1, 1}};


struct Cell {
  int x, y;
  int moves;

};


int bfs (pii start, pii end, set<pii> &visited, set<pii> &allowed) {
  queue<Cell> q;
  q.push({start.first, start.second, 0});
  visited.insert(start);
  int res = -1;
  while (!q.empty()) {
    Cell v = q.front();
    q.pop();
    int x = v.x;
    int y = v.y;
    int moves = v.moves;
    // cout << x << " " << y << " " << moves << endl;

    if (make_pair(x,y) == end) {
      return moves;
    }

    REPLIST(dir, directions) {
      int newX = x + dir.first;
      int newY = y + dir.second;
      if (newX >= 1 && newX <= 1e9 && newY >= 1 && newY <= 1e9) {
        if (allowed.count({newX, newY}) && !visited.count({newX, newY})) {
          visited.insert({newX, newY});
          q.push({newX, newY, moves+1});
        }
      }
    }
  }
  return res;
}

void solve(int tt){
  int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
  int n; cin >> n;
  set<pii> adj;
  set<pii> visited;
  REP(i,0,n) {
    int r, a, b; cin >> r >> a >> b;
    REP(i,a,b+1) {
      adj.insert({r,i});
    }
  }
  pii start = {x0, y0};
  pii end = {x1, y1};
  cout << bfs(start, end, visited, adj) << endl;
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
