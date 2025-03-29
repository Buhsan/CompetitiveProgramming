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

#define PRINTLiST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
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
    string a, b;
    cin>>n;
    cin>>a;
    cin>>b;
    int cnt = 0;
    // P(a);
    // P(b);
    int k = 0;
    REPV(i, n-1, 0){
        int j = i;
        int x = -1;
        while(j > 0){
            if(a[j] != a[j-1]){
                x = j;
                break;
            }
            j--;
        }
        if (x != -1){
            a[x] = b[k];
            a.erase(a.begin()+(x-1));
            cnt++;
            k++;
            // P(k);
            // P(b[k]);
            // P(a);
        }
    }

    if(cnt == n-1){
        PRINT("YES");
    }
    else{
        PRINT("NO");
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