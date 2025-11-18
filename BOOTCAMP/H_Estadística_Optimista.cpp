#include <iostream>
#include <iomanip>

using namespace std;
 
int main()
{
    int n;
    cin >> n;
    double res = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        double a;
        cin >> a;
        if(a >= 5.00) {
            cnt++;
            res+=a;
        }
    }
    cout<< fixed << setprecision(2) <<res/cnt<<endl;

    return 0;
}