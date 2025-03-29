#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)


 int main(){
    int t, n, k;
    vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result = 0;
        cin >> n;
        vector<int> values(n);
        REP(j, 0, n){
            cin >> values[j];
        }
        auto maxi = max_element(values.begin(), values.end());
        if ((maxi - values.begin()) == 0){
            result = 0;
            // cout << "break" << endl;
            // break;
        }
        else if((maxi - values.begin()) == values.size()-1){
            result = maxi - values.begin();
        }
        else{    
            vector<int> a(values.begin(), maxi);
            vector<int> b(maxi+1, values.end());
            auto maxiA =  max_element(a.begin(), a.end());
            auto maxiB = max_element(b.begin(), b.end());
            if (*maxiA == *maxiB){
                result = 1;
            }
            else if(*maxiA < *maxiB){
                result = maxi - values.begin();
            }
            else if(*maxiA > *maxiB){

                result = (maxiA - a.begin()) + 1;
                // if((maxiA - a.begin()) == 0){
                //     result = 1;
                // }
                // else{
                //     result = (maxiA - a.begin()) + 1;
                // }
            }
        }
        // int maxA =  *max_element(a.begin(), a.end());
        // int maxB = *max_element(b.begin(), b.end());
        // int maxA = *max_element(values.begin(), values.end());
    //     for(int i:a){
    //     cout << i << endl;  
    // }    
    // cout << "aaa" <<endl;
    // for(int i:b){
    //     cout << i << endl;  
    // }
        // code


        res.push_back(result);
    }
    
    for(int i:res){
        cout << i << endl;  
    }

    return 0;
}