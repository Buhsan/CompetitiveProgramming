#include <bits/stdc++.h>
using namespace std;


struct Instrument {
  int total, currPages, numPages;
};


struct Comparator {
  
  bool operator() (const Instrument &a, const Instrument &b) {
    return a.currPages < b.currPages;
  }
};


void print(priority_queue<Instrument, vector<Instrument>, Comparator> &pq) {
  priority_queue<Instrument, vector<Instrument>, Comparator> tmp;
  cout << "\n--------\n";
  while (!pq.empty()) {
    tmp.push(pq.top());
    cout << "Total: " << pq.top().total << " currentPages: " << pq.top().currPages << " pages: " << pq.top().numPages << '\n';
    pq.pop();
  }
  pq = tmp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  while (cin >> p >> n) {
    priority_queue<Instrument, vector<Instrument>, Comparator> pq;
    int cnt = p;
    for (int i = 0; i < n; i++) {
      int a; cin >> a;
      pq.push({a, a, 1});
      cnt--;
    }
    while (cnt > 0) {
      //print(pq);
      Instrument curr = pq.top();
      pq.pop();
      curr.numPages+=1;
      pq.push({curr.total, (int)ceil(curr.total/(double)curr.numPages), curr.numPages});
      cnt--;
    }
    Instrument res = pq.top();

    cout << res.currPages << '\n';
  
  }
  return 0;
}
