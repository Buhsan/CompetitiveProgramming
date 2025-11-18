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

#define TESTCASES true

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



bool canCross(const vector<int>& positions, int initialJump) {
    int currentJump = initialJump;
    for (size_t i = 1; i < positions.size(); ++i) {
        int distance = positions[i] - positions[i - 1];
        if (distance > currentJump) {
            return false;
        }
        if (distance == currentJump) {
            --currentJump;
        }
    }
    return true;
}

int findMinimumJump(const vector<int>& positions) {
    int left = 1;
    int right = *max_element(positions.begin(), positions.end());
    int result = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canCross(positions, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            result = 
            left = mid + 1;
        }
    }

    return result;
}


void solve(int tt){
    // int n;
    // cin >> n;
    // vint a(n);
    // vint rest;
    // REP(i,0,n){
    //     cin>>a[i];
    //     if(i==0){
    //         rest.push_back(a[i]);
    //     }
    //     else{
    //         rest.push_back(a[i]-a[i-1]);
    //     }
    // }
    // SORTINCR(a);
    // int res = findMinimumJump(a);
    // PRINT(res);
    // // int max = rest[MAX(rest)];

    // // int l = 1;
    // // int r = a[MAX(a)];
    // // int res = r;
    // // int num = count(rest.begin(), rest.end(), max);
    // // int val = max + (num>1 ? 1 : 0);

    // // while(l <= r){
    // //     int mid = (l+r)/2;
    // //     if (mid >= val){
    // //         res = mid;
    // //         r = mid - 1;
    // //     }
    // //     else {
    // //         l = mid + 1;
    // //     }
    // // }
    // // PRINT(res);

    ll n;
    cin >> n;

    ll maxSalto = 0;
    ll ultimaPiedra = 0;
    ll num;
    for (ll i = 0; i < n; i++) {
        cin >> num;
        ll salto = num - ultimaPiedra;
        if (salto > maxSalto) {
            maxSalto = salto;
        } else if (salto == maxSalto) {
            maxSalto++;
        }
        ultimaPiedra = num;
    }

    cout << maxSalto << endl;

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