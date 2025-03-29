#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool isEven(int num){
    if (num % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int t, n, k;
    vector<string> res;
    string result;
    cin >> t;
    for (int j =0; j < t; j++){
        cin >> n >> k;
        int num = (n*(n+1))/2 - ((n-k)*(n-k+1))/2;
        // for(int i = n-k; i<n; i++){
        //     num += (i+1);
        // }
        if(isEven(num)){
            res.push_back("YES");
        }
        else{
            res.push_back("NO");
        }
    }
    res.push_back(result);
    for(string i:res){
        cout << i << endl;  
    }

    return 0;



}