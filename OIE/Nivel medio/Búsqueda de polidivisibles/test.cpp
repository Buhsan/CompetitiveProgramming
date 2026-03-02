#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve (int currDigit, ll &curr, int d) {
  cout << curr << '\n';

  if (currDigit == d) return;

  for (int i = 0; i <= 9; i++) {
    curr*=10;
    curr+=i;

    if (!(curr % (currDigit+1))) {
      solve (currDigit + 1, curr, d);
    }

    curr /= 10;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, d;
  while (cin >> n >> d) {
    ll curr = n;

    int len = 0;
    ll aux = n;
    while (aux) {
      aux/=10;
      len++;
    }

    solve(len, curr, d);
    cout << "---\n";
  }
  return 0;
}
