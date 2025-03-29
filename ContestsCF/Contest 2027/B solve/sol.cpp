// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i=0; i<n; i++) cin >> A[i];
        int best = 0;
        for (int i=0; i<n; i++) {
            int curr = 0;
            for (int j=i; j<n; j++) {
                if (A[j] <= A[i]) {
                    curr += 1;
                }
            }
            best = max(best, curr);
        }
        cout << n - best << "\n";
    }
  return 0;
}