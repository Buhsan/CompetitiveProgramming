#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to compute factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to check divisibility
vector<int> find_divisors(int d, int n) {
    vector<int> divisors;
    long long fact = factorial(n);
    set<int> odd_digits = {1, 3, 5, 7, 9};

    // Only consider odd divisors of `d`
    for (int k : odd_digits) {
        if (d % k == 0) {
            // Check if k divides 10^n! - 1
            long long mod = 1;
            for (int i = 0; i < fact; i++) {
                mod = (mod * 10) % k;
            }
            if (mod == 1) {
                divisors.push_back(k);
            }
        }
    }
    return divisors;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int d, n;
        cin >> n >> d;
        
        vector<int> divisors = find_divisors(d, n);
        cout << "Odd divisors from 1 to 9: ";
        for (int k : divisors) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}
