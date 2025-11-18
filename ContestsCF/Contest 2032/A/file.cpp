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
    long long int t, n, k;
    // vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int m = 1;
        cin >> n >> k;
        if((n/2)+1 == k){
            m = 1;
            
        }
        else{
            m = -1;
        }
        if (m == -1){
            cout << m << endl;
        }
        else{
            cout << m <<endl;
            cout << m <<endl;
        }
        // cout << "" << endl;
    }
    
    // for(int i:res){
    //     cout << i << endl;  
    // }

    return 0;
}