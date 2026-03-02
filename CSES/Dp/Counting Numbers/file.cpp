#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
// basicamente contar las posibilidades en la profundidad (n) y luego hacer posibilidades(n) * posibilidades(n+1)
//
//
 
ll solve2(int id, int digit, bool lower, bool upper, string &a, string &b, bool leadingZeros, vector<vector<vector<vector<ll>>>> &dp) {
  if (id == a.size()-1) {
    // cout << endl;
 
    return 1; // devolver lo calculado (mentira)
  }
  int ans = 0;
 
 
  // if (firstTry)
 
  //mirar lower para poner el start y upper para poner el end
  int start = 0;
  int end = 9;
  // upper = (b[id] == (digit + '0'));
  if (lower) start = (a[id+1] - '0');
  if (upper) end = (b[id+1] - '0');
  // if (id == a.size()-2) {
  //   // cout << start << " " << end << endl;
  //   // cout << "+" << (end - start) + (lower || upper) << endl;
  //   return (end-start+1) - (start <= digit && digit <= end) ;
  // }
  // cout << "for digit: " << digit << " in pos: " << id+1 << " start is " << start << " and end is " << end << endl;
  
 
  leadingZeros = (leadingZeros && start == 0);
  for (int i = start; i <= end; i++) {
    // cout << "putting on " << id+1 << " digit " << i << endl;
    if (i == digit && !(i == 0 && leadingZeros)) continue;
    // cout << i;
    // cout << b[id+1] << " " << (char)(i+'0') << endl;
    ans += solve2(id+1, i, (lower && a[id+1] == (i + '0')), (upper && b[id+1] == (i + '0')), a, b,leadingZeros, dp);
  }
 
  return ans;
}
 
ll solve(int id, int digit, bool lower, bool upper, string &a, string &b, bool leadingZeros, vector<vector<vector<vector<ll>>>> &dp) {
  if (dp[id][digit][lower][upper] != -1) {
    return dp[id][digit][lower][upper]; 
  }
  if (id == a.size()) {
    // cout << endl;

    return dp[id][digit][lower][upper] = 1; // devolver lo calculado (mentira)
  }

  dp[id][digit][lower][upper] = 0;
 
  // if (firstTry)
 
  //mirar lower para poner el start y upper para poner el end
  int start = 0;
  int end = 9;
  // upper = (b[id] == (digit + '0'));
  if (lower) start = (a[id] - '0');
  if (upper) end = (b[id] - '0');
  // if (id == a.size()-1) {
  //   // cout << start << " " << end << endl;
  //   // cout << "+" << (end - start) + (lower || upper) << endl;
  //
  //   // return dp[id][digit][lower][upper] = (end-start+1) - (start <= digit && digit <= end);
  // }
  // cout << "for digit: " << digit << " in pos: " << id+1 << " start is " << start << " and end is " << end << endl;
  
 
  for (int i = start; i <= end; i++) {
    // cout << "putting on " << id+1 << " digit " << i << endl;
    if (i == digit && !(i == 0 && leadingZeros)) continue;
    // cout << i;
    // cout << b[id+1] << " " << (char)(i+'0') << endl;
    bool nLower = (lower && a[id] == (i + '0'));
    bool nUpper = (upper && b[id] == (i + '0'));
    dp[id][digit][lower][upper] += solve(id+1, i, nLower, nUpper, a, b,leadingZeros && i == 0, dp);
  }
 
  return dp[id][digit][lower][upper];
}
 
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  string x, y;
  cin >> x >> y;
  int maxi = max(x.size(), y.size());
  stringstream a, b;
  // cout << "maxi: " << maxi << endl;
  a << setw(maxi) << setfill('0') << x;
  b.fill('0');
  b << setw(maxi) << setfill('0') << y;
 
  string f, s;
  f = a.str();
  s = b.str();
 
  if (f > s) swap(f,s);
  // cout << f << " " << s << endl;
 
  vector<vector<vector<vector<ll>>>> dp(20, vector<vector<vector<ll>>>(10, vector<vector<ll>>(2, vector<ll>(2, -1))));
 
  ll ans = solve(0, 0, true, true, f, s, f[0] == '0', dp);
  cout << ans << '\n';
  // cout << "ans: " << ans << endl;
  
  return 0;
}
