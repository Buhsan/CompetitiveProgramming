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
    cin >> n;
    vint a(n);
    vint b;
    FILL(a);
    int x = 0;

    REPLIST(i, a){
        if (i > x){
            b.push_back(1);
            x++;
        }
        else if (i < x){
            b.push_back(-1);
            x--;
        }
        else {
            b.push_back(0);
        }
    }
    int l = 0, r = 0;
    PRINTLIST(b);
    REP(i, 0, n){
        int sum = -2;
        P(b[i]);
        if(b[i] < 1){
            P(b[i]);
            REP(j, i, n){
                if(a[j] < 1){
                    P(a[j]);
                    // int q = 0;
                    // REP(k, i+1, j) {
                    //     q += a[k];
                    // }
                    int q = accumulate(b.begin()+i+1, b.begin()+j-1, 0);
                    if (q<sum){
                        l = i;
                        r = j;
                        sum = q;
                    }
                    break;
                }
            }
        }
        else {
            
            PRINT(n-1);
            return;
        }
    }
    b.erase(b.begin()+l, b.begin()+r);
    PRINT(accumulate(b.begin(), b.end(), 0));
    // PRINTLiST(b);
    //CODE
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