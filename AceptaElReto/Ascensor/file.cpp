#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <unordered_map>
#include <functional>
#include <set>
#include <math.h>

// #include <bits/stdc++.h>;
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
#define PLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
// #define FILL(list) for (auto elem : list) cin>>elem
// #define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define FILL(list) for (auto &elem : list) cin>>elem
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

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

#define TESTCASES false

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

void solve(int tt){
    string s;
    vint a;
    bool read = true;
    while (getline(cin, s) && read) {
        int last = 0;
        int res = 0;
        int num;
        int i = 0;
        stringstream temp(s);
        while ( temp >> num ){
            if(num < 0 && i == 0){
                read = false;
                break;
            }
            else{
                if(num != -1){
                    if(i > 0) res += abs(last - num);
                    last = num;
                }
            }
            i++;
        }
        if(read) PRINT(res);
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