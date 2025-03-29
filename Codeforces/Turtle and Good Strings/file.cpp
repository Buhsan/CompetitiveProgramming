#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
#define FILL(list) for (auto elem : list) cin>>elem;
#define REPLIST(i, list) for (auto i : list)

#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINTLST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
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

// int repString(string k, string w){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,w.size()) == w) cnt++;
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

void solve(int tt){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.substr(0,1) == s.substr(n-1,1)) {PRINT("NO"); return;}
    else if (n>=2) PRINT("YES");
    else PRINT("NO");

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