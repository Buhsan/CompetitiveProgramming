#include <bits/stdc++.h>
using namespace std;

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

#define TESTCASES 0

void solve(long long tt){
  long long n;
  while (cin >> n && n) {
    vector<pair<long long, long long>> ciclistas(n);
    for (long long i = 0; i < n; i++) {
      long long pos, vel;
      cin >> pos >> vel;

      ciclistas[i] = {pos, vel};
    }

    sort(ciclistas.begin(), ciclistas.end(), [](const pair<long long, long long>& a, const pair<long long, long long> &b) {
      return a.first < b.first;
    });

    long long tiempoMin = LLONG_MAX;

    for (long long i = 0; i < n - 1; i++) {
      if (ciclistas[i].first == ciclistas[i + 1].first) {
        tiempoMin = 0;
        break;
      }
      if (ciclistas[i].second > ciclistas[i + 1].second) {
        long long numerador = abs(ciclistas[i].first - ciclistas[i + 1].first);
        long long denominador = abs(ciclistas[i + 1].second - ciclistas[i].second);

        if (denominador != 0) {
          long long tiempo = numerador / denominador;
          tiempoMin = min(tiempo, tiempoMin);
        }
      }
    }

    if (tiempoMin == LLONG_MAX) cout << "SIN COLISION" << endl;
    else cout << tiempoMin << endl;
  }
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
