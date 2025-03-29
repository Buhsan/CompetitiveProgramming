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
// #define FILL(list) for (auto elem : list) cin>>elem
#define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
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

int cards(int a1, int a2, int b1, int b2){
    int cnt1 = 0, cnt2 = 0;
    if(a1>b1){
        cnt1++;
        if(a2>b2){
            cnt1++;
        }
        else if (b2>a2){
            cnt2++;
        }
    }
    else if (b1>a1) cnt2++;
    if(cnt1>cnt2){
        return 1;
    }
    else return 0;

}

void solve(int tt){
    int a1, a2, b1, b2;
    cin>>a1>>a2>>b1>>b2;
    int cnt = 0;
    cnt += cards(a1, a2, b1, b2);
    cnt += cards(a1, a2, b2, b1);
    cnt += cards(a2, a1, b2, b1);
    cnt += cards(a2, a1, b1, b2);
    
    // if(a1>b1&&a2>=b2) cnt++;
    // if(a1>b2&&a2>=b1) cnt++;
    // if(a2>b1&&a1>=b2) cnt++;
    // if(a2>b2&&a1>=b1) cnt++;

    PRINT(cnt);

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