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

// #define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINTLIST(list) for (auto &elem : list) { cout << elem << " "; } cout<<endl;
// #define PRINT(...) ((cout << ... << " "), cout << endl)
#define PRINT(v) cout << v << endl
#define P(v) cout << #v << ": " << v << endl
// #define P(...) ((cout << ((cout << #__VA_ARGS__ << " = ") , ... , (cout << __VA_ARGS__ << " "))), cout << endl)



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


bool yn(bool cond) {
  cond ? PRINT("SI") : PRINT("NO");
  return cond;
}

#define TESTCASES 0

void solve(int tt){
  int ancho, largo, pasillo1, pasillo2;
  while(cin >> largo >> ancho >> pasillo1 >> pasillo2) {
    if (ancho > largo) swap (ancho, largo);
    // if (pasillo1 > pasillo2) swap(pasillo1,pasillo2);
    bool res = false;
    // double num = sqrt((pasillo1*pasillo1) - (ancho*ancho)) + sqrt((pasillo2*pasillo2) - (ancho*ancho));
    // res = num <= largo;
    // res = (sqrt(pasillo1*pasillo1 - ancho*ancho) + sqrt(pasillo2*pasillo2 - ancho*ancho)) <= largo;
    double low = 0.0, high = (double)largo;

    while (high - low > 1e-9) {
      double mid = (high + low) / 2.0;
      double mid1 = largo - mid;
      double h1_sq = mid * mid + ancho * ancho;
      double h2_sq = mid1 * mid1 + ancho * ancho;

      if (h1_sq <= pasillo1 * pasillo1 && h2_sq <= pasillo2 * pasillo2) {
        res = true;
        break;
      } 
      if (h1_sq > pasillo1 * pasillo1) {
        high = mid - 0.0000000001;
      } else {
        low = mid + 0.0000000001;
      }
    }

    yn(res);
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
