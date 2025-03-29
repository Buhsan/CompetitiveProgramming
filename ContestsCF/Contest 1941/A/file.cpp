#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
#define PRINT(v) cout << v << endl

/*
accumulate
max_element
upper_bound
sort
*/

// bool isEven(int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, n, m, k;
    // vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        REP(i, 0, n) cin >> a[i];
        REP(i, 0, m) cin >> b[i];
        int cnt = 0;
        REP(i, 0, n){
            REP(j, 0, m){
                if (a[i] + b[j] <= k) cnt++;
            }
        }
        PRINT("AAAAAA");
        PRINT(cnt);
    }
    
    return 0;
}
