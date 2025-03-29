#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)


bool isEven(int num){
    if (num % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int t, n, k;
    cin >> t;
    vector<vector<int>> res(2);
    REP(i, 0, t){
        int max = 0, min = 0;
        int countOne = 0, countZero = 0;
        cin >> n;
        vector<int> val(2*n);
        REP(i, 0, 2*n){
            int j;
            cin >> j;
            val[i] = j;
            if(j == 1) countOne++;
            else countZero++;
        }
        // cout << "countOne " << countOne <<" " << "countZero " << countZero <<endl;
        max = countOne;
        if (countOne > n){
            max = 2*n - countOne;
        }
        if(isEven(countOne)){ 
            min = 0;
            if(countOne == 2*n){
                max = 0;
            }
        }
        else if (countOne > 0){
            min = 1;
        }
        else if (countOne == 0){
            min = 0; 
        }
        cout << min <<" " << max <<endl;
        // res[i][0] = min;
        // res[i][0] = max;

    }
    
    // for(vector<int> i:res){
    //     cout << i[0] <<  " " << i[1]<< endl;  
    // }

    return 0;
}