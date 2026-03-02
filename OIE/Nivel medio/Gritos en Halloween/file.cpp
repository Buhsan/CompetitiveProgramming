#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> L(100);
ll max_n = 0;

void precompute() {
    L[1] = 3;
    max_n = 1;
    for (int i = 2; i < 70; i++) {
        if (L[i - 1] > (LLONG_MAX - (i + 2)) / 2) {
            break;
        }
        L[i] = 2 * L[i - 1] + (i + 2);
        max_n = i;
    }
}

char solve(ll n, ll k) {
    if (n == 1) {
        if (k == 1) return 'B';
        if (k == 2) return 'U';
        return 'H';
    }

    if (n > max_n) {
        return solve(n - 1, k);
    }

    if (k <= L[n - 1]) {
        return solve(n - 1, k);
    }

    k -= L[n - 1];
    ll middle_len = n + 2;
    if (k <= middle_len) {
        if (k == 1) return 'B';
        if (k == middle_len) return 'H';
        return 'U';
    }

    k -= middle_len;
    return solve(n - 1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    ll n, k;
    while (cin >> n >> k) {
        cout << solve(n, k) << "\n";
    }

    return 0;
}
