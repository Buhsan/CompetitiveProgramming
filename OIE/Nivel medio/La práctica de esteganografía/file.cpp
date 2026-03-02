#include <bits/stdc++.h>

using namespace std;


struct Candidate {
  vector<pair<int,int>> v; // pair = {val, id};
};

struct Comparator{
  bool operator()(const Candidate& a, const Candidate& b) {
    if (a.v.size() == b.v.size()) return a.v[a.v.size()-1].second < b.v[b.v.size()-1].second;
    return a.v.size() < b.v.size();
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r;
  while (cin >> r) {
    unordered_map<int,int> clave;
    vector<int> pass(r);
    unordered_map<int,int> waiting;
    for (int i = 0; i < r; i++) {
      cin >> pass[i];
      clave[pass[i]] = i;
      if (i) {
        waiting[i] = 0;
      }
    }

    int first = pass[0];
    int last = pass[r-1];

    int res = INT_MAX;

    priority_queue<Candidate, vector<Candidate>, Comparator> pq;
    priority_queue<Candidate, vector<Candidate>, Comparator> aux2;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      int num; cin >> num;
      cout << "num: " << num << endl;
      if (!clave.count(num)) {cout << "skipping" << endl; continue;}


      if (num == first) {
        cout << "first number encountered" << endl;
        Candidate c;
        c.v.push_back({num,i});
        pq.push(c);
        aux2.push(c);
        waiting[1]++;
      } else if (!pq.empty()){
        if (!waiting[clave[num]]) {cout << "skipping, because no one is waiting" << endl; continue;}
        cout << "starting interation to find right chain" << endl;
        priority_queue<Candidate, vector<Candidate>, Comparator> aux;
        bool find = false;
        // cout << pq.size() << endl;
        while (!find) {
          Candidate cand = pq.top();
          cout << "cand: ";
          for (auto p : cand.v) {
            cout << "{" << p.first << ", " << p.second << "} ";
          }
          cout << endl;
          pq.pop();
          aux2.pop();

          // if (find) {
          //   aux.push(cand);
          //   continue;
          // }
          if (cand.v.size() == pass.size() - 1 && num == last) {
            cout << "find the correct chain with size: " << (i - cand.v[0].second + 1) << endl;
            res = min(res, (i - cand.v[0].second + 1));
            for (int j = 1; j < r; j++) {
              waiting[j]--;
            }
            cout << "new res: " << res << endl;
            find = true;
          } else if (cand.v.size() == clave[num]) {
            cout << "find the next elem, pushing " << num << endl;
            cand.v.push_back({num,i});
            waiting[cand.v.size()]++;
            aux.push(cand);
          } else {
            cout << "find nothing" << endl;
            aux.push(cand);
          }
        }
        cout << "coping new cands:" << endl;
        while (!aux.empty()) {
          Candidate a = aux.top();
          for (auto p : a.v) {
            cout << "{" << p.first << ", " << p.second << "} ";
          }
          cout << endl;
          aux2.push(a);
          aux.pop();
        }
        pq = aux2;
      }
      cout << endl;
    }
    cout << res << '\n';

  }

  return 0;
}
