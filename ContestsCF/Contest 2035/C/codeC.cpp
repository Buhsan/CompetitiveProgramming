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
    cin.tie(0)->sync_with_stdio(0);
    int t, n, k;
    vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result = 0;
        cin >> n;
        int num = 0;
        REP(j, 1, n+1){
            if (isEven(j)){
                num = num|j;
            }
            else{
                num = num&j;
            }
            result = max(result,num);
        }
        REP(j, 1, n+1){
            if(j < n) cout << j << " ";
            else cout << j << endl;
        }

        // code
    }
    
    // for(int i:res){
    //     cout << i << endl;  
    // }

    return 0;
}
