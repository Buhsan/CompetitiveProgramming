#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    int min;
    cin>>min;
    int h = min / 60;
    int m = min % 60;

    cout << setfill('0') << setw(2) << (h+12)%24 << ":" << setfill('0') << setw(2) << m << endl;

    return 0;
}