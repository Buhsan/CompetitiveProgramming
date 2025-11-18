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
        vector<int> num(n);
        if (n==1 || n==3){
            result = -1;
        }
        else if (n == 2){
            result = 0;
            num[0]=6;
            num[1]=6;
        }
        else{
            // result = 0;
            if(isEven(n)){
                fill(num.begin(), num.end() - 2, 3);
                fill(num.end() - 2, num.end(), 6);
                // if(!isEven(n/2)){
                // }
                // else{
                //     fill(num.begin(), num.begin() + (n/2), 3);
                //     fill(num.begin() + (n/2), num.end(), 6);
                //     // num.resize(n/2, 6);
                // }
            }
            else{
                // fill(num.begin(), num.end(), 3);
                num[0] = 3;
                num[n-1] = 6;
                num[n-2] = 6;
                num[n-3] = 3;
                num[n-4] = 6;
                fill(num.begin(), num.end()-4, 3);
            }
        }



        // code
        if(result == -1){
            cout << result << endl;
        }
        else{
            for(int i:num){
                cout << i;  
            }
            cout<< "" << endl;
        }
        // res.push_back(result);
    }
    
    

    return 0;
}