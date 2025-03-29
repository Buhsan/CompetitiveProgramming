#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        if (n < 3) {
            cout << -1 << endl;
            continue;
        }
        
        if (n % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        
        string result = "";
        for (int i = 0; i < n / 3; ++i) {
            result += "366";
        }
        
        cout << result << endl;
    }
    return 0;
}
