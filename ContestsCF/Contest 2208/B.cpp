// WA
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

multiset<pair<int,int>> ms;

bool del(int i) {
  //cout << "start deleting: " << endl;
  int id = 0;
  for (auto it = ms.begin(); it != ms.end(); it++) {
    if ((*it).second == i) {
      ms.erase(it);
      return true;
    }
    id++;
  }

  return false;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> v(n);
    ms.clear();
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (ms.size() < k) {
/*        cout << "current window: ";
        for (auto it = ms.begin(); it != ms.end(); it++) {
          cout << (*it).first << " <-> " << (*it).second << " ";
        }
        cout << endl;*/
        ms.insert({v[i], i});
      } else {
        q.push({v[i], i});
      }
    }
    int res = 0;
    if (k == n) {
      res = m / v[p-1];
    } else {
      int id = 0;
      int pos = p-1;
      int last = k-1;
      while (m > 0) {
        //cout << "current window: ";
        /*for (auto it = ms.begin(); it != ms.end(); it++) {
          cout << (*it).first << " <-> " << (*it).second << " ";
        }*/
        //cout << endl;
        //cout << "m: " << m << " sol: " << res << endl;
        if (pos <= last) {
          //cout << "enter 1 " << endl;
          m-=v[p-1];
          if (m >= 0) {
            res++;
          }
          del(pos);
          //cout << ( ? "deleted" : "not found") << endl;
          pos = n-1;
        } else {
          //cout << "enter 2 " << endl;
          m-=(*ms.begin()).first;
          q.push(*ms.begin());
          ms.erase(ms.begin());
          ms.insert(q.front());
          q.pop();
          pos--;
        }
      }
    }


    cout << res << '\n';
  }

  return 0;
}
