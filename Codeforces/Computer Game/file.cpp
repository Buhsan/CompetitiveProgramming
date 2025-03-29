#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <stack>

using namespace std;


typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vint;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define P(v) cout << #v << ": " << (v) << endl
// #define FILL(list) for (auto elem : list) cin>>elem;
#define FILL(list) for (int i = 0; i < list.size(); ++i) cin >> list[i]
#define REPLIST(i, list) for (auto i : list)

// #define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINTLIST(a) cout << #a << ": "; for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout<<endl;
#define PRINT(v) cout << v << endl

#define SORTINCR(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDECR(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()

#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()

#define TESTCASES true

/*
accumulate
max_element
upper_bound
sort
*/

// int repString(string k, string w){
//     int cnt = 0;
//     REP(i,0,k.size()){
//         if (k.substr(i,w.size()) == w) cnt++;
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

void dfs_it(vector<vint> adj, int n){
    vector<bool> visited (2*n, false);
    stack<int> st;
    st.push(0);
    int exit = 2*n-1;
    while (st.size() > 0){
        int v = st.top();
        st.pop();
        // P(v);
        if (v == exit){
            PRINT("YES");
            return;
        }
        if(!visited[v]){
            visited[v] = true;
            REPLIST(i, adj[v]){
                if(!visited[i]){
                    st.push(i);
                }
            }
        }
    }
    PRINT("NO");
}

void dfs_rec(vector<vint> adj, int v, vector<bool> &visited, bool &find){
    int exit = adj.size()-1;
    if( v != exit){
        visited[v]=true;
        REPLIST(i, adj[v]){
            // P(i);
            if(!visited[i]){
                dfs_rec(adj, i, visited, find);
            }
        }
    }
    else{
        find = true;
        return;
    }
}

void solve(int tt){
    int n, m, r;
    cin >> n;
    string s;
    string s1;
    cin >> s;
    cin >> s1;
    vint b; 
    vint c;
    REPLIST(i,s){
        b.push_back(i-'0');

    }
    REPLIST(j,s1){
        c.push_back(j-'0');
    }
    vector<vector<int>> a{b,c};
    // REPLIST(b,a){
    //     PRINTLIST(b);
    // }
    vector<vector<int>> adj(2*n, vector<int>());
    REP(i, 0, 2){
        REP(j, 0, n){
            int id = i*n+j;
            // P(id);
            if(i == 0 && j == 0){
                // P(id);
                // P(a[i+1][j]);
                if(a[i][j+1] == 0) adj[id].push_back(id+1);
                if(a[i+1][j] == 0) adj[id].push_back(id+n);
                if(a[i+1][j+1] == 0) adj[id].push_back((i+1)*n+(j+1));
            }
            else if(i == 0 && j == (n-1)){
                if(a[i][j-1] == 0) adj[id].push_back(n-2);
                if(a[i+1][j] == 0) adj[id].push_back(2*n-1);
                if(a[i+1][j-1] == 0) adj[id].push_back(2*n-2);
            }
            else if(i==1 && j == 0){
                if(a[i][j+1] == 0) adj[id].push_back(id+1);
                if(a[i-1][j] == 0) adj[id].push_back(id-n);
                if(a[i-1][j+1] == 0) adj[id].push_back((i-1)*n+(j+1));
            }
            else if(i==1 && j == (n-1)){
                    if(a[i][j-1] == 0) adj[id].push_back(id-1);
                    if(a[i-1][j] == 0) adj[id].push_back(id-n);
                    if(a[i-1][j-1] == 0) adj[id].push_back(n-2);
            }
            else if (i==0){
                if(a[i][j+1] == 0) adj[id].push_back(id+1);
                if(a[i][j-1] == 0) adj[id].push_back(id-1);
                if(a[i+1][j] == 0) adj[id].push_back(n+j);
                if(a[i+1][j+1] == 0) adj[id].push_back(n+j+1);
                if(a[i+1][j-1] == 0) adj[id].push_back(n+j-1);
            }
            else if (i == 1){
                if(a[i][j+1] == 0) adj[id].push_back(id+1);
                if(a[i][j-1] == 0) adj[id].push_back(id-1);
                if(a[i-1][j] == 0) adj[id].push_back(j);
                if(a[i-1][j+1] == 0) adj[id].push_back(j+1);
                if(a[i-1][j-1] == 0) adj[id].push_back(j-1);
            }
        }
    }

    for(vint y : adj){
        PRINTLIST(y);
    }

// DFS ITERATIVO
    dfs_it(adj, n);

// DFS RECURSIVO
//     vector<bool> visited (2*n, false);
//     bool find = false;
//     dfs_rec(adj, 0, visited, find);
//     if(find){
//         PRINT("YES");
//     }
//     else {PRINT("NO");}
}



int main(){
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