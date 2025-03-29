#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl

/*
accumulate
max_element
upper_bound
sort
*/

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
    cin>>n;
    
    if(n > 0){
        cout << n << endl;
    }
    else{
        string k = to_string(n);
        int a = stoi(k.substr(0, k.size()-1));
        int b = stoi(k.substr(0,k.size()-2) + k.substr(k.size()-1,1));
        // P(a);
        // P(b);
        if(a>b) cout << a << endl;
        else cout << b << endl;
    }

    return 0;
}