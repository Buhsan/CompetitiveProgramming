#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    int old = -1;
    while(cin >> n) {
        if(old != -1) {
            if(old > n) cout<<"B";
            else if (old < n) cout << "S";
            else cout << "I";
        }
        old = n;
    }

    return 0;
}