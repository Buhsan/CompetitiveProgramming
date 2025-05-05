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

int get_k (int n, int k, int i) {
    if (n == 1) return i;
    if (k <= n / 2) {
        return (i-1 + 2*(k-1))%n + 1;
    } else {
        int new_k = k - (n / 2) - i;
        int new_n = n - n / 2;
        int res = get_k(new_n, new_k, (n%2 ? i+2 : i));
        return 2 * res - 1;
    }
}


int josephus_kth_eliminated(int n, int k, int start) {
    if (n == 1) return start;

    int half = n / 2;

    if (k <= half) {
        // Removed this round: every second child starting from (start + 1)
        return ((start % n + (k - 1) * 2) % n == 0) ? n : (start % n + (k - 1) * 2) % n;
    } else {
        // In next round
        int survivors = n - half;
        int new_k = k - half;

        // Calculate new start (depends on whether n is even or odd)
        int new_start;
        if (n % 2 == 0) {
            new_start = start;
        } else {
            new_start = (start + 2) % n;
            if (new_start == 0) new_start = n;
        }

        int survivor_index = josephus_kth_eliminated(survivors, new_k, new_start);
        int mapped = ((start - 1 + 2 * (survivor_index - 1)) % n) + 1;
        return mapped;
    }
}






#define TESTCASES 1

void solve(int tt){
  ll n, k; cin >> n >> k;
  cout << josephus_kth_eliminated(n,k, 1) << endl;
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
