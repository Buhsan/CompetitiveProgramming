#include <iostream>
 
using namespace std;
 
int main()
{
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int res = a*5 + b*7 + c*13;
    if (c != 0) res -= 13;
    else if (b != 0) res -=7;
    else if (a != 0) res -= 5;

    cout << res << endl;

    return 0;
}