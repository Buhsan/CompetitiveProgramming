#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end(), [](ll &a, ll &b) {
    return a > b;
  });

  ll low = 0;
  ll high = d + 5;

  ll ans = -1;
  while (high >= low) {
    ll mid = (high - low) / 2 + low;

    queue<ll> q;
    {
      int i = 0;
      while (q.size() < mid + 1) {
        if (i < n) {
          q.push(a[i]);
          i++;
        }
        else {
          q.push(0);
        }
      }
    }

    ll coins = 0;
    for (int i = 0; i < d; i++) {
      coins += q.front();
      q.push(q.front());
      q.pop();
    }

    if (coins >= c) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }

  if (ans == -1) cout << "Impossible\n";
  else if (ans > d) cout << "Infinity\n";
  else cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
