#include <bits/stdc++.h>

using namespace std;


struct Instrument {
  int total, numPages;
};


struct Comparator {
  
  bool operator() (const Instrument &a, const Instrument &b) {
    int num1 = ceil(a.total/(double)a.numPages);
    int num2 = ceil(b.total/(double)b.numPages);
    return num1 < num2;
  }
};


void print(priority_queue<Instrument, vector<Instrument>, Comparator> &pq) {
  priority_queue<Instrument, vector<Instrument>, Comparator> tmp;
  cout << "\n--------\n";
  while (!pq.empty()) {
    tmp.push(pq.top());
    cout << "Total: " << pq.top().total << " pages: " << pq.top().numPages << '\n';
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
      pq.push({a, 1});
      cnt--;
    }
    while (cnt > 0) {
      //print(pq);
      Instrument curr = pq.top();
      pq.pop();
      //cout << "current: " << curr.total << " " << curr.numPages << endl;
      pq.push({curr.total, curr.numPages+1});
      cnt--;
    }
    Instrument res = pq.top();

    cout << ceil(res.total/(double)res.numPages) << '\n';
  
  }
  return 0;
}
