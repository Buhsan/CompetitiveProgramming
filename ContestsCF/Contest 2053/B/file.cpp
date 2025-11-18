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
typedef pair<ll,ll> pll;

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

// bool yn(bool cond, string tr = "YES", string fls = "NO") {
//     if (cond) PRINT(tr);
//     else PRINT(fls);
//     return cond;
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

bool isIn(set<int> nums, pii limit){
    int n = 0;
    REPLIST(i,nums) {
        if(limit.first <= i && i <= limit.second) n++;
    }
    return (limit.second-limit.first)+1-n > 0;
}

void solve(int tt){
    int n;
    cin>>n;
    set<int> nums;
    set<int> nums1;
    vector<pair<pii,int>> vp;
    string res (n, '0');
    vector<bool> boolean(2*n, false);
    map<pii,int> freq;
    REP(i,0,n){
        int a, b;
        cin >> a >> b;
        if(a==b) nums1.insert(a);
        if (a == b && !freq.count({a,b})) nums.insert(a), boolean[a-1] = true;
        freq[{a,b}]++;
        vp.push_back({{a,b}, i});
    }
    if(nums.size() == 0){
        string r(n, '1');
        PRINT(r);
        return;
    }
    // PLIST(boolean);
    REP(i,0,n){
        if (vp[i].first.first == vp[i].first.second && freq[vp[i].first] == 1) res[vp[i].second] = '1';
        // else if (vp[i].first.first == vp[i].first.second && freq[vp[i].first] > 1) res[vp[i].second] = '0';
        else if(vp[i].first.first != vp[i].first.second){
          int q = vp[i].first.first;
          int w = vp[i].first.second;
        //   cout<<q<<" "<<w<<endl;
        //   test[q-1] = true;
        //   test[w-1] = true;
        //   PLIST(test);
        //   vector<bool> aux(test.begin()+q-1, test.begin()+w);
        //   PLIST(aux);
        //   P(num);
        //   P((w-q)+1);
            int num = accumulate(boolean.begin()+q-1, boolean.begin()+w, 0);
            if(num < (w-q)+1) res[vp[i].second] = '1';
        } 
    }
    PRINT(res);
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