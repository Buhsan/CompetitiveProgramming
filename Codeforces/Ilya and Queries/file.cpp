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
int res = 0;
void strSearch(string str1, string q, int search){

    // char arr[] = "geeks";
    // int res = 0;
    size_t found = str1.find(q, search);
    if (found != string::npos){
        // res+=strSearch(str1, q, found+1);
        res++;
    }
    else{
        // break;
        return;
    }
    strSearch(str1, q, found+1);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, n;
    string k;
    // vector<int> res;
    cin >> k;
    n = k.size();
    cin >> t;
    int a, b;
    REP(i, 0, t){
        int result;
        cin >> a >> b;
        string q = k.substr(i,1);
        string str1 = k.substr(a-1,(b-a));
        P(q);
        P(str1);
        res = 0;
        strSearch(str1, q, 0);
        cout << res << endl;
        cout << endl;
    }
    

    return 0;
}