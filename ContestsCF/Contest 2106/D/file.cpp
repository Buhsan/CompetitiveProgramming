#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define PLIST(list) cout << #list << ": "; for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
#define PRINT(v) cout << v << endl
#define P(v) cout << #v << ": " << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

const ll MOD = 1e9 + 7;

#define TESTCASES 1

bool is_possible(const vint& a, const vint& b, int k) {
    int n = a.size(), m = b.size();
    int j = 0;
    bool used = false;

    for (int i = 0; i <= n; ++i) {
        int val = (i < n ? a[i] : INT_MIN); 

        if (j < m && val >= b[j]) {
            ++j;
        } else if (!used && j < m && k >= b[j]) {
            ++j;
            used = true;
        }

        if (j == m) return true;
    }

    return false;
}

int find_min_k(vint& a, vint& b) {
    SORTINCR(b);

    if (is_possible(a, b, 0)) return 0;

    int left = 1, right = 1e9, ans = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(a, b, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

void solve(int tt){
    int n, m;
    cin >> n >> m;
    vint a(n), b(m);
    FILL(a);
    FILL(b);
    PRINT(find_min_k(a, b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    if (TESTCASES) {
        int tt; cin >> tt;
        REP(i, 1, tt+1) {
            solve(i);
        }
    } else solve(1);

    return 0;
}
