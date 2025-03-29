    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long int ll;
    typedef vector<ll> vll;
     
    #define REP(i, a, b) for (int i = a; i < b; ++i)
    #define REPV(i, a, b) for (int i = a; i >= b; --i)
    #define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
    #define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
    #define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
    #define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
    #define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
    #define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
    #define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
    #define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
    #define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
    #define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))
     
    const ll MOD = 1e9 + 7;
     
    #define TESTCASES true 
     
    void solve() {
      ll n;
      cin >> n;
      string s;
      cin >> s;
     
      ll ans = 0;
     
      vll ovejas;
      REP (i, 0, s.length()) {
        if (s[i] == '*') ovejas.push_back(i);
      }
     
      ll ovejaMedio = ceil(ovejas.size() / 2.0f) - 1;
     
      for (int i = 0; i < ovejas.size(); i++) {
        if (i == ovejaMedio) continue;
     
        ll dest = ovejas[ovejaMedio];
     
        if (i > ovejaMedio) dest += i - ovejaMedio;
        else dest -= ovejaMedio - i;
     
        ll dist = abs(dest - ovejas[i]);
        // cout << "dist oveja " << i << ": " << dist << endl;
     
        ans += dist;
      }
     
      cout << ans << endl;
    }
     
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      int t = 1;
     
      if (TESTCASES) cin >> t;
      while (t--) {
        solve();
      }
     
      return 0;
    }
