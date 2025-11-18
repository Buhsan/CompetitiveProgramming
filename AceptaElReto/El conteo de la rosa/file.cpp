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

int contarDigitos(int inicio, int final) {
  int p = log10(inicio) + 1;
  int p2 = log10(final) + 1;

  int cnt = 0;

  for (int i = p; i <= p2; i++) {
    int minRelativo = pow(10, i - 1);
    int maxRelativo = pow(10, i) - 1;

    if (p == i && p2 == i) {
      minRelativo = inicio;
      maxRelativo = final;
    }
    else if (i == p) {
      minRelativo = inicio;
    } else if (i == p2) {
      maxRelativo = final;
    }

    int nums = maxRelativo - minRelativo + 1;
    // cout << "para i = " << i << " hay " << nums << " nums max = " << maxRelativo << " min = " << minRelativo << endl;
    cnt += nums * i;
  }

  return cnt;
}

void solve(int tt){
  int inicio, final;
  while (cin >> inicio >> final) {
    if (!inicio && !final) break;

    int alto = final;
    int bajo = inicio;
    int medio;

    while (alto >= bajo) {
      medio = (alto - bajo) / 2 + bajo;
      int int1 = contarDigitos(inicio, medio);
      int int2 = contarDigitos(medio + 1, final);
      if (int1 == int2) { break;}
      // cout << "int1 = " << int1 << " (" << bajo << " - " << medio << ")" << endl;
      // cout << "int2 = " << int2 << " (" << medio + 1 << " - " << alto << ")" << endl;
      // cout << medio << endl;

      if (int1 > int2) {
        alto = medio - 1;
      } else {
        bajo = medio + 1;
      }
    }
    int int1 = contarDigitos(inicio, medio);
    int int2 = contarDigitos(medio + 1, final);
    if (int1>int2) medio--;
    cout << medio << endl;
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
