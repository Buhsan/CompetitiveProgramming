#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// #include <char>


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
    int t, n, k, d;
    vector<int> res;
    cin >> t;
    REP(i, 0, t){
        int result;
        string s;
        cin >> s;
        cin >> n;
        size_t found = s.find("1100");
        REP(j, 0, n){
            cin >> k >> d;
            if (found != string::npos){
                if ((k-1)< found && (k-1) > found+3){
                    cout << "YES" << endl;
                    // cout << found << endl;
                }
                else{
                    s.replace(k-1, 1, to_string(d));
                    if(s.substr(found, 4) == "1100"){
                        cout << "YES" << endl; 
                        // cout << "SUBSTR " << s.substr(found, 4) << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
                
            }
            else {
                // cout << "NO" << endl;
                s.replace(k-1, 1, to_string(d));
                size_t found1 = s.find("1100");
                if (found1 != string::npos){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }

            }
            
            

        }
        // code
    }
    
    for(int i:res){
        cout << i << endl;  
    }

    return 0;
}