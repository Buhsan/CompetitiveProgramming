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


#define TESTCASES 0

struct Intervalo {
  double ini, fin;
  int pos;
};

void solve(int tt){
  double a, b;
  while (cin >> a >> b) {
    int n;
    cin >> n;

    vector<Intervalo> intervalos(n);
    for (int i = 0; i < n; i++) {
      double ini, fin;
      cin >> ini >> fin;
      intervalos[i] = {ini, fin, i};
    }

    sort(intervalos.begin(), intervalos.end(), [](const Intervalo &x, const Intervalo &y) {
      if (x.ini == y.ini) return x.fin < y.fin;
      return x.ini < y.ini;
    });

    vector<Intervalo> usado;

    if (intervalos[0].ini > a) {
      cout << "impossible" << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      if (intervalos[intervalos.size() - 1].fin >= b) break;

      if ((intervalos[i].ini <= a && intervalos[i].fin <= b) || (intervalos[i].fin >= b && intervalos[i].ini >= b)) continue;

      if (!usado.empty()) {
        Intervalo ultimoIntervalo = intervalos[usado.size() - 1];

        if (ultimoIntervalo.fin < intervalos[i].ini) {
          break;
        }
        if (ultimoIntervalo.ini == intervalos[i].ini) {
          usado.pop_back();
          usado.push_back(intervalos[i]);
        } else usado.push_back(intervalos[i]);
      } else usado.push_back(intervalos[i]);
    }

    double actual = a;
    for (int i = 0; i < usado.size(); i++) {
      actual = max(actual, usado[i].fin);
    }
    if (actual < b) {
      cout << "impossible" << endl;
    } else {
      cout << usado.size() << endl;
      for (int i = 0; i < usado.size(); i++) {
        cout << usado[i].pos << " ";
      }
      cout << endl;
    }
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
