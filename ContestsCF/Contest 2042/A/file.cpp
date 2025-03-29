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

void prefix_sum(vint a, vint &pref_sum){
    // l, r -> [0,+inf]
    // vint pref_sum(a.size());
    pref_sum[0] = a[0];
    REP(i, 1, a.size()){
        pref_sum[i] = pref_sum[i - 1] + a[i];
    }
}

void solve(int tt){
    int n, k;
    cin >> n >> k;
    vint a(n);
    FILL(a);
    int max = a[MAX(a)];
    int sum = accumulate(a.begin(), a.end(), 0);
    // P(sum);
    if (sum < k){
        PRINT(k-sum);
        return;
    }
    else if(k == max){
        PRINT(0);
        return;
    }
    else{
        SORTDECR(a);
        int cnt = 0;
        int s = 0;
        vint pref_sum(n);
        prefix_sum(a, pref_sum);
        REPV(i, n-1, 0){
            if(pref_sum[i] == k){
                PRINT(0);
                return;
            }
            else if(pref_sum[i] < k){
                PRINT(k-pref_sum[i]);
                return;
            }
        }
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