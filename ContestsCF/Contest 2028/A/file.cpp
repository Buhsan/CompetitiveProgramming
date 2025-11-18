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
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    // P(s);
    // P(a);
    // P(b);
    // cout<<endl;
    // PRINTLIST(s);
    int x = 0, y = 0, i = 0;
    bool res = false;


    // while(x < a || y < b){
    //     if (x == 0 || y == 0){
    //         PRINT("NO");
    //         return;
    //     }
    //     // else if (x > a || y > b){
    //     //     break;
    //     // }
    //     // P(i);
    //     // P(x);
    //     // P(y);
    //     // cout<<endl;
    // }
    // else if ()
    REP(j, 0, 30){
        REP(i, 0, n){
            if (s[i] == 'N'){
                y++;
            }
            else if (s[i] == 'E'){
                x++;
            }
            else if (s[i] == 'S'){
                y--;
            }
            else if (s[i] == 'W'){
                x--;
            }
            if (x == a && y == b){
                PRINT("YES");
                return;
            }
            if (x != 0 && y != 0){
                if ((a/x) == (b/y)){
                    res = true;
                }
            }
        }

        if (x == 0 || y == 0 ){
            PRINT("NO");
            return;
        }
    }
    

    // cout << endl;
    // int a1 = 0, b1 = 0, repA = -1, repB = -2;
    // REP(i, 0 , a){
    //     a1 += x;
    //     if (a1 == a){
    //         repA = i;
    //     }
    // }
    // REP(i, 0 , b){
    //     b1 += y;
    //     if (b1 == b){
    //         repB = i;
    //     }
    // }
    // P(a1);
    // P(b1);
    if (x == a && y == b){
        PRINT("YES");
    }
    else PRINT("NO");
    // vint a(n);
    // FILL(a);
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