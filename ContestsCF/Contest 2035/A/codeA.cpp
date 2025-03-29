#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define REP(i, a, b) for (long long int i = a; i < b; ++i)
#define REPV(i, a, b) for (long long int i = a; i >= b; --i)


// bool isEven(long long int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


int main(){
    cin.tie(0)->sync_with_stdio(0);
    long long int t, n, m, r, c;
    vector<long long int> res;
    cin >> t;
    REP(i, 0, t){
        long long int result = 0;
        cin >> n >> m >> r >> c;
        if (r == n && c == m){
            result = 0;
        }
        else{
            // if ()
            result = (abs(n-r))*m;
            result += (abs((m-1))*abs((n-r))) + abs((m-c));
        }
        // code
        res.push_back(result);
    }
    
    for(long long int i:res){
        cout << i << endl;  
    }

    return 0;
}