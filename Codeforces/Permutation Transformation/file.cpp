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

#define TESTCASES true

/*
accumulate
max_element
upper_bound
sortв
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

void bfs(vint a, vint  &res){
    queue<pair<int, int>> q;
    int n = a.size();
    int maxi = MAX(a);
    q.push({maxi, 0});
    vector<bool> visited(n+1, false);
    visited[n] = true;
    while(!q.empty()){
        pair<int, int> v = q.front();
        q.pop();
        P(v.first);
        res[v.first] = v.second;
        visited[v.first] = true;
        if(v.first < n-1){
            vint right(a.begin()+v.first+1, a.end());
            PLIST(right);
            int max = n;
            int aux = 1;
            // P(n);
            // P(v.first);
            // PLIST(visited);
            // P(visited[4]);
            while(visited[max] && aux < n){
                // PLIST(visited);
                // P(1);
                // P(max);
                // P(visited[max]);
                vint e(a.begin()+aux, a.end());
                PLIST(e);
                if(max == n) aux=v.first+1;
                max = max_element(a.begin()+aux, a.end()) - a.begin();
                aux +=1;
                // P(2);
                // P(max);
                // P(aux);
                // cout<<endl;
                
            }
            P(max);
            // int max = max_element(a.begin()+v.first+1, a.end()) - a.begin();
            // P(max);
            if(!visited[max] &&right.size() > 0) q.push({max, v.second+1});
        }
        if(v.first > 0){
            vint left(a.begin(), a.begin()+v.first);
            PLIST(left);
            int aux = 1;
            int max = n;
            while(visited[max]){
                // if(max == n) aux=v.first;
                max = max_element(a.begin(), a.begin()+(v.first-aux)) - a.begin();
                aux +=1;
            }
            P(max);
            if(!visited[max] &&left.size() > 0) q.push({max, v.second+1});
        }
        cout<<endl;
    }
}



void solve(int tt){
    int n;
    cin>>n;
    vint a(n);
    FILL(a);
    vint res(n);
    bfs(a, res);
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