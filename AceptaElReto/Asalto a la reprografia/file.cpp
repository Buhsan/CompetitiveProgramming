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
#define P(v) cout << #v << ": " << (v) << endl
#define PLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
// #define FILL(list) for (auto elem : list) cin>>elem
// #define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define FILL(list) for (auto &elem : list) cin>>elem
#define REPLIST(i, list) for (auto i : list)

#define PRINTLIST(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINT(v) cout << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define PPAIR(a) cout << #a << ": "; for (auto j : a) { cout<<"{"<<j.first<<" "<<j.second<<"} "; } cout<<endl;
#define PAIR(a) cout << #a << ": "; cout<<"{"<<a.first<<" "<<a.second<<"} "; cout<<endl;

#define TESTCASES true

int repString(string k, string search){
    int cnt = 0;
    REP(i,0,k.size()){
        if (k.substr(i,search.size()) == search) cnt++;
    }
    return cnt;
}

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

string findPattern(const string& sequence) {
    int n = sequence.size();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            string pattern = sequence.substr(0, len);
            bool matches = true;
            for (int i = 0; i < n; i += len) {
                if (sequence.substr(i, len) != pattern) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                return pattern;
            }
        }
    }
    return sequence;
}



void get_pattern(vector<string> s){
    vint rest;
    int n = s.size();
    string s1 = "";
    // PLIST(s);
    REP(i,1,n){
        // P(i);
        // P(s[1]);
        // P(s[i] -'0');
        s1+=to_string(stoi(s[i])-stoi(s[i-1]));
    }
    string pattern;
    // P(s1);
    // string new_s = s1;
    // string pattern = new_s;
    // while(pattern == new_s && pattern.size() > 0){
    //     pattern = findPattern(new_s);
    //     if(pattern == new_s) new_s.erase(new_s.end()-1), pattern = new_s;
    // }
    // // string res = "";
    // int result = stoi(s[s.size()-1]);
    // // P(result);
    // // P(pattern);
    // if(pattern.size() == 0){
    //     result+=s1[0] -'0';
    // }
    // else result+=pattern[s1.size()%pattern.size()] -'0';
    // PRINT(result);
    P(s1);
    set<char> c(s1.begin(), s1.end());
    if(c.size() == 1) pattern = s1[0];
    else{
        // pattern = s1;
        // REPV(len, n, 1){
        //     string aux = s1.substr(0, len);
        //     if(repString(s1, aux) == 0) break;
        //     pattern = aux;
        // }
        P(s1.size()/2);
        REPV(len, s1.size()/2, 1){
            P(len);
            string aux = s1.substr(0, len);
            P(aux);
            P(repString(s1, aux));
            if(repString(s1, aux) == 0) break;
            pattern = aux;
            P(pattern);
        }
    }
    P(pattern);
    int result = stoi(s[s.size()-1]);
    // if(pattern.size() == 0){
    //     result+=s1[0] -'0';
    // }
    // else result+=pattern[s1.size()%pattern.size()] -'0';
    result+=pattern[s1.size()%pattern.size()] -'0';
    PRINT(result);
    cout<<endl;
}

void solve(int tt){
    string s;
    int m = 0;
    while(getline(cin,s) && s != "0"){
        string pattern = "";
        if(m) {
            string s1;
            stringstream temp(s);
            vector<string> s2;
            while(getline(temp, s1, ' ')){
                s2.push_back(s1);
            }
            get_pattern(s2);
        }
        m = 1-m;
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