#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define PRN(v) cout << #v << ": " << (v) << endl


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
    // vector<int> res;
    cin >> t;
    // sort(a.begin(), a.end(), [] (int a, int b) {return a<b;});
    REP(i, 0, t){
        int result;
        cin >> n >> k;
        int sumT = 0;
        vector <int> sumBtl(k);
        // vector <int> cntBtl(k);
        vector<vector<int>> btl(k);
        REP(i, 0, k){
            int type = 0;
            int a, b;
            cin >> a >> b;
            btl[i].push_back(a);
            btl[i].push_back(b);
            sumT += btl[i][1];
            // cntBtl[btl[i][0] - 1] += 1;
            sumBtl[btl[i][0] - 1] += btl[i][1];
        }
        if(n >= k){
            result = sumT;
        }
        else{
            // int j = 0;
            result = 0;
            sort(sumBtl.begin(), sumBtl.end(), [] (int a, int b) {return a>b;});
            // auto a = n;
            result = accumulate(sumBtl.begin(), sumBtl.begin()+n, 0);
            // while(n > 0){
            //     auto maxi = max_element(sumBtl.begin(), sumBtl.end());
            //     int max = *maxi;
            //     result += max;
            //     sumBtl.erase(maxi);
            //     n--;
            // }
        }
        // REP(j, 0, sumBtl.size()){
        //     if(j < sumBtl.size()-1) {cout << sumBtl[j] << " ";}
        //     else {cout << sumBtl[j] << endl;}
        // }
        // cout << "sumT " << sumT << endl;
        
        // cout << result << endl;
        PRN(sumT);
        // code
    }
    

    return 0;
}