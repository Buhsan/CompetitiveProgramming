#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c) {
    vector<int> input(c);
    for (int i = 0; i < c; i++) cin >> input[i];

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    if (n > c) {
      cout << c + 1 << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      pq.push({input[i],i});
    }

    for (int i = n; i < c; i++) {
      pair<ll,int> curr = pq.top();
      pq.pop();
      pq.push({curr.first + input[i], curr.second});
    }
    cout << pq.top().second + 1<< '\n';
  }
  

  return 0;
}
