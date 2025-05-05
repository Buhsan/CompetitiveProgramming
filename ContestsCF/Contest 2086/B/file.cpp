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
  int n, k;
  ll x;
  cin >> n >> k >> x;

  vll a(n), prefix(2*n);
  FILL(a);
  prefix[0] = a[0];
  for (int i = 1; i < 2*n; i++) {
    int id = i%n;
    prefix[i] = prefix[i - 1] + a[id];
  }
  // if (k > 1) {
  // }
  // P(x);
  // PLIST(prefix);
  ll res = 0;

  ll sum = accumulate(a.begin(), a.end(), 0);
  // ll sum = prefix[n-1];
  double decimal = (double)x/sum;
  ll div = x/(sum);
  ll enter = x/sum;
  double dec = decimal-enter;
  ll num = n*dec;
  P(enter);
  P(decimal);
  P(dec);
  P(num);
  P(div);
  ll b = (n-num)*(k-enter);
  // P(b);
  // P(k- (enter+1));
  if (div > k) res = 0;
  else res = (enter != 0)+ (k - div)*n - num;
  // if (n == 1 && floor(dec) != dec) res--;



  // if (prefix[2*n-1] >= x) {
  //   int id = LOWER(prefix, x);
  //   P(id);
  //   res = ((2*n)-id)*(k-1);
  // }
  // else {
  //   ll sum = accumulate(a.begin(), a.end(), 0);
  //   // ll sum = prefix[n-1];
  //   double decimal = (double)x/sum;
  //   ll div = x/(sum);
  //   ll enter = x/sum;
  //   double dec = decimal-enter;
  //   ll num = n*dec;
  //   // P(enter);
  //   // P(dec);
  //   // P(num);
  //   // P(div);
  //   ll b = (n-num)*(k-enter);
  //   // P(b);
  //   // P(k- (enter+1));
  //   if (div > k) res = 0;
  //   else res = 1 +  (k - div)*n - num;
  //   // if (n == 1 && floor(dec) != dec) res--;
  // }
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
