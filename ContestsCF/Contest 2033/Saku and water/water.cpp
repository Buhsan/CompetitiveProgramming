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


int diag(vector<vector<int>> a, int i, int j){
    vector<int> ar;


    return 0;
}

int main(){
    int t, n, k;
    vector<int> res;
    
    cin >> t;
    REP(i, 0, t){
        int result = 0;
        cin >> n;
        int b;
        vector<vector<int>> a(n);
        REP(i, 0, n){
            REP(j, 0, n){
                cin >> b;
                a[i].push_back(b);
            }
        }
        REP(i, 0, n){
            int num = 0;
            int j = 0;
            // vector<int> ar;
            // REP(j, 0, n){
            //     ar.push_back(a[i][j]);
            // }
            int min = 0;
            while(i + num < n && j + num < n){
                if (a[i+num][j+num] < min) min = a[i+num][j+num];
                num++;
            }
            result += -min;
        }

        REP(j, 1, n){
            int num = 0;
            int i = 0;
            int min = 0;
            while(i + num < n && j + num < n){
                if (a[i+num][j+num] < min) min = a[i+num][j+num];
                num++;
            }
            result += -min;
        }

        

        cout << result << endl;
    }
    

    return 0;
}