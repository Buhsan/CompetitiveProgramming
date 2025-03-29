#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){ 
    int n, m;
    cin >> n >> m;
    int nums = 0;
    if (n > m){cout << n-m << endl; return 0;}
    while (n<m){
        if (m % 2 == 0){
            m/=2;
            nums++;
        }
        else{ 
            m +=1;
            nums++;
        }
    }
    cout << (n-m)+nums;
    return 0;
}