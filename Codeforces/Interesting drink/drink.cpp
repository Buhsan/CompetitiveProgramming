#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
 

int main()
{
    int a, b, n;
    
    vector<int> res;

    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++){
        cin >> values[i];
    }

    sort(values.begin(), values.end(), [] (int a, int b) {return a<b;});
    cin >> a;
    for (int i = 0; i < a; i++){
        cin >> b;
        res.push_back(upper_bound(values.begin(), values.end(), b) - values.begin());
    }

    for (int i:res){
        cout<<i<<endl;
    }
    return 0;
}   