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
    int t, n, k;
    vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result = 0;
        cin >> n;
        int a, b;
        vector<int> aList, bList;
        REP(j, 0, n){
            cin >> a >> b;
            aList.push_back(a);
            bList.push_back(b);
        }
        int maxA = *max_element(aList.begin(), aList.end());
        int maxB = *max_element(bList.begin(), bList.end());

        // cout << maxA << "<>" << maxB<<endl;
        // result = (maxA+maxB)*2;
        // code
        res.push_back((maxA+maxB)*2);
    }
    
    for(int i:res){
        cout << i << endl;  
    }

    return 0;
}