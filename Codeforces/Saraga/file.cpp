#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <unordered_map>
#include <functional>
#include <set>
#include <math.h>

// #include <bits/stdc++.h>;
using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(abc) cout << #abc << ": " << (abc) << endl
#define PLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
// #define FILL(list) for (auto elem : list) cin>>elem
// #define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINT(abc) cout << abc << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

#define TESTCASES false

// int repString(string k, string search){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,search.size()) == search) cnt++;
//     }
//     return cnt;
// }

// bool isEven(int num){
//     if (num % 2 == 0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// bool yn(bool cond, string tr = "YES", string fls = "NO") {
//     if (cond) PRINT(tr);
//     else PRINT(fls);
//     return cond;
// }

// int prefix_sum(vint a, int l, int r){
//     // l, r -> [0,+inf]
//     vint pref_sum(a.size());
//     pref_sum[0] = a[0];
//     REP(i, 1, a.size()){
//         pref_sum[i] = pref_sum[i - 1] + a[i];
//     }
//     return pref_sum[r] - (l == 0 ? 0:pref_sum[l-1]);
// }

void solve(int tt){
  string s;
  string s1;
  cin >> s;
  cin >> s1;
  vint abc(26);
  REP(i,1,s.size()){
      if(abc[s[i] - 'a'] > 0){continue;}
      abc[s[i] - 'a'] = i;
    //   P(s[i]);
    //   P(s[i] - 'a');
  }
//   PLIST(abc);
  string res = "-1"; 
  bool found = false;
  REPV(i, s1.size()-2, 0){
      if(abc[s1[i] - 'a'] <= 0){continue;}
      ll len = abc[s1[i] - 'a'] + s1.size() - i;
      if(!found || len < res.size()){
          found = true;
          res = s.substr(0, abc[s1[i] - 'a']) + s1.substr(i);
      }
  }
  PRINT(res);
  // if(s==s1 && !(s.size()==1 && s1.size()==1)){PRINT(s); return;}
  // else if((s.size()==1 && s1.size()==1)){
  //   PRINT(-1);
  //   return;
  // }
  // string s2(s);
  // string s3(s1);
  // reverse(s2.begin(), s2.end());
  // reverse(s3.begin(), s3.end());
  // // if(s==s3 || s1 == s2){PRINT(s); return;}
  // string res = "";
  // REP(i,0,s.size()){
  //   REPV(j, s1.size(), 0){
  //     if(s[i] == s1[j]){
  //       string auxs(s.begin(), s.begin()+i);
  //       string auxs1(s1.begin()+j, s1.end());
  //       string ns = "2";
  //       string ns1 = "1";
  //       int newi = i;
  //       int newj = j;
  //       while(newi-1>=0 && newj+1<s1.size()+1 && auxs+auxs1 != ns+ns1){
  //         // P(1);
  //         string ns(s.begin(), s.begin()+(newi--));
  //         string ns1(s1.begin()+(newj++), s1.end());
  //         // P(ns);
  //         // P(ns1);
  //         // P(auxs+auxs1);
  //         if(auxs+auxs1 == ns+ns1 && !(ns.size() == ns1.size() && ns.size() == 1)){
  //           res = auxs+auxs1;
  //           PRINT(res);
  //           return;
  //         }
  //       }
  //       // P(auxs+auxs1);
  //     }
  //   }
  // }
  // PRINT(-1);
  // return;
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
