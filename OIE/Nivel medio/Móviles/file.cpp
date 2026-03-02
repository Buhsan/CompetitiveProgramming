#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// bool balanced = true;


pair<bool, ll> solve () {
  int pi, di, pd, dd; cin >> pi >> di >> pd >> dd;
  // cout << "movil: " << pi << " " << di << " " << pd << " " << dd << endl;
  bool balanced = true;
  if (pi == 0) {
    // cout << "buscando el submovil izquierdo" << endl;;
    pair<bool, ll> s = solve();
    balanced &= s.first;
    pi = s.second;
    // cout << "encontrado con el equilibrio: " << s.first << " y peso " << s.second << endl;
  } 
  if (pd == 0){
    // cout << "buscando el submovil derecho" << endl;;
    pair<bool, ll> s1 = solve();
    balanced &= s1.first;
    pd = s1.second;
    // cout << "encontrado con el equilibrio: " << s1.first << " y peso " << s1.second << endl;
  }

  ll right = (long long)(pi*di);
  ll left = (long long)(pd*dd);

  // cout << "comprobando el balance entre " << right << " y " << left << endl; 
  return {balanced&(right==left), pi+pd};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    // cout << "TESTCASE " << t << endl;
    pair<bool, ll> sol = solve();
    cout << (sol.first ? "SI" : "NO") << '\n';
  }


  return 0;
}
