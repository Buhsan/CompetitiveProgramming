#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 
int main()
{
    int a, b, n, res = 0;
    cin >> n;
    vector<int> result;
 
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        res = 0;
        if (a >= b){
            res = a;                
        }
        else {
            int aux = b - a;
            if (a-aux <= 0) res = 0;
            else res = a-aux;
        }   

        result.push_back(res);
    }
 
    for (int i:result){
        cout << i << endl;
    }
    return 0;
}   