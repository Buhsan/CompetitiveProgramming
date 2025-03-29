#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)


// bool isEven(int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// bool check(vector<int> v, vector<int> v1, int k){
//     int a1, a2, b1, b2;
//     a1 = v[2] - v[0];
//     b1 = v[3] - v[1];
//     a2 = v1[2] - v1[0];
//     b2 = v1[3] - v1[1];
//     if ((a1*b1)+(a2*b2) == 0){
//         if (sqrt(pow(a1+0.0, 2+0.0) + pow(b1+0.0, 2+0.0)) >=k && sqrt(pow(a2+0.0, 2+0.0) + pow(b2+0.0, 2+0.0)) >=k){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     else { return false;}
// }


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, x, y, k;
    // vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result;
        vector<int> ab(4);
        vector<int> cd(4);
        cin >> x >> y >> k;
        if ( k <= x && k <= y){
            // cout << "ONE" << endl;
            ab[0] = 0;
            ab[1] = 0;
            ab[2] = x;
            ab[3] = 0;
            cd[0] = 0;
            cd[1] = 0;
            cd[2] = 0;
            cd[3] = y;
        }
        else{
            // cout << "TWO" << endl;
            int num = min(x, y);
            ab[0] = 0;
            ab[1] = num;
            ab[2] = num;
            ab[3] = 0;
            cd[0] = 0;
            cd[1] = 0;
            cd[2] = num;
            cd[3] = num;
        }

        REP(j, 0, 4){
            if(j < 3) {cout << ab[j] << " ";}
            else {cout << ab[j] << endl;}
        }
        // cout << "a" << endl;
        REP(b, 0, 4){
            if(b < 3) {cout << cd[b] << " ";}
            else {cout << cd[b] << endl;}
        }

        // if (check(ab, cd, k)){
        //     cout << "TRYE" << endl;
        // }
        // else{
        //     cout << "FALSE" << endl;
        // }
    }

    return 0;
}