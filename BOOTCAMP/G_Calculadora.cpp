#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    int n, o;
    char c;
    cin >> n >> c >> o;
    
    switch(c) {
        case '+':
            cout << n + o << endl;
            break;
        case '-':
            cout << n - o << endl;
            break;
        case '*':
            cout << n*o << endl;
            break;
        case '/':
            if (o == 0) cout << "ERROR" << endl;
            else {
                cout << fixed << setprecision(2) << n*1.0 / o << endl;
            }
            break;
    }

    return 0;
}