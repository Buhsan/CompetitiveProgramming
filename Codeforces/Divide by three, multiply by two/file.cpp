#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
#define PLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;

// #define FILL(list) for (auto elem : list) cin>>elem
#define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINT(v) cout << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define TESTCASES false

/*
accumulate
max_element
upper_bound
sort
*/

// int repString(string k, string search){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,search.size()) == search) cnt++;
//     }
//     return cnt;
// }

// bool isEven(int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// int prefix_sum(vint a, int l, int r){
//     // l, r -> [0,+inf]
//     vint pref_sum(a.size());
//     pref_sum[0] = a[0];
//     REP(i, 1, a.size()){
//         pref_sum[i] = pref_sum[i - 1] + a[i];
//     }
//     return pref_sum[r] - (l == 0 ? 0:pref_sum[l-1]);
// }

void bfs(ll first, vll &res, vll a, set<ll> a_members){
    set<ll> visit;
    queue<ll> q;
    q.push(first);
    while(!q.empty()){
        ll v  = q.front();
        q.pop();
        if(a_members.count(v) == 1) res.push_back(v);
        visit.insert(v);
        ll max = MAX(a);
        // P(v);
        // P(max);
        // P(v*2);
        // P(v/3);

        if(v % 3 == 0 && !(visit.count(v/3))) q.push(v/3), visit.insert(v/3);
        if(v * 2  <= a[max] && !(visit.count(v*2))) q.push(v*2), visit.insert(v*2);
    }
}



void solve(int tt){
    ll n;
    cin >> n;
    vll a(n);
    vll res;
    FILL(a);
    set<ll> a_members(a.begin(), a.end());
    // SORTINCR(a);
    SORTDECR(a);
    REP(i, 0, n){
        bfs(a[i], res, a, a_members);
        // PLIST(res);
        if(res.size() == n) break;
        else res.clear();
    }
    PRINTLIST(res);


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