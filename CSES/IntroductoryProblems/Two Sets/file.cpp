#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        long long target = sum / 2;
        vector<int> a, b;

        for (int i = n; i >= 1; --i) {
            if (i <= target) {
                a.push_back(i);
                target -= i;
            } else {
                b.push_back(i);
            }
        }

        cout << a.size() << "\n";
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n" << b.size() << "\n";
        for (int x : b) cout << x << " ";
        cout << "\n";
    }

}
