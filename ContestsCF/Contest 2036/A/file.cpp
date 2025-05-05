#include <iostream>
#include <algorithm>
#include <vector>
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


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, n, k;
    vector<int> res;
    cin >> t;
    REP(i, 0, t){
        string result;
        cin >> n;
        vector<int> val(n);
        REP(i, 0, n){
            // int j;
            cin >> val[i];
            // val[i] = j;
        }

        REP(i, 0, n){
            if(i+1 < n){
                if(abs(val[i]-val[i+1]) == 5 || abs(val[i]-val[i+1]) == 7){
                    result = "YES";
                }
                else{
                    result = "NO";
                    break;
                }
            }
        }
        cout << result << endl;
         


        // code
    }
    

    return 0;
}
