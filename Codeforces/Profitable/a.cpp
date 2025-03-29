#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases
    while (t--) {
        long long a, b;
        cin >> a >> b; // a = Alice's coins, b = initial minimum required for "Profitable" deposit

        if (a >= b) {
            // Alice already has enough coins to open the Profitable deposit
            cout << a << endl;
        } else {
            // Calculate how many coins she can deposit in Profitable after depositing in Unprofitable
            cout << max(0LL, a - (b - a + 1) / 2) << endl;
        }
    }
    return 0;
}
