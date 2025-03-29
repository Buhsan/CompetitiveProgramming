#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int k, t, n;
    int num = 0;
    
    vector<int> res;

    cin >> t;
    
    for (int i = 0; i < t; i++){
        cin >> n >> k;
        vector<int> values(n);
        for(int j = 0; j < n; j++){
            cin >> values[j];
        }
        int m = 0;
        int num = 0;
        for(int b = 0; b < n; b++){
            // cout<<values[b] << " <> " << k<<endl;
            if(values[b] >= k){
                // cout<<"a"<<endl;
                m += values[b];
            }
            else if(values[b] == 0 && m != 0){
                // cout<<"b"<<endl;
                m -= 1;
                num++;
            }
        }
        res.push_back(num);
    }
    for (int a:res){
        cout << a << endl;
    }
    return 0;
}