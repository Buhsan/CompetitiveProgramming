#include <bits/stdc++.h>
using namespace std;

struct Pack {
  int a, b, precio;
};

int solve(int i, int goalA, int goalB, vector<vector<vector<int>>> &dp, vector<Pack> &packs) {
  int n = packs.size();
  if (goalA == 0 && goalB == 0) return 0;
  if (i == n) return INT_MAX;
  if (dp[i][goalA][goalB] != INT_MAX) {
    return dp[i][goalA][goalB];
  }

  //no comprar
      dp[i][goalA][goalB] = min(dp[i][goalA][goalB], solve(i+1, goalA, goalB, dp, packs));
  //comprar
      int num = solve(i+1, max(goalA-packs[i].a, 0), max(goalB-packs[i].b, 0), dp, packs);
      if (num != INT_MAX) {
        dp[i][goalA][goalB] = min(dp[i][goalA][goalB], num + packs[i].precio);
      }

  return dp[i][goalA][goalB];
  
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<bool> isPrime(10000, true);
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i < 10000; i++) {
    if (isPrime[i]) {
      for (int j = 2 * i; j < 10000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int neededA = 0;
  int neededB = 0;

  string line;
  getline(cin, line);
  int cnt = 1;
  while (getline(cin, line)) {
    if (line == "Productos del almacen de Don Diego Provencio") {
      break;
    }

    stringstream ss(line);
    string nombre;
    int a, b;
    ss >> nombre >> a >> b;

    if (isPrime[cnt]) {
      neededA += a;
      neededB += b;
    }
    cnt++;
  }

  int cntA, cntB, precio;
  vector<Pack> packs;
  while (cin >> cntA >> cntB >> precio) {
    packs.push_back({cntA, cntB, precio});
  }

  int n = packs.size();
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(1001, vector<int>(1001, INT_MAX)));

  int res = INT_MAX;

  for (int a = 1; a <= 1000; a++) {
    for (int b = 1; b <= 1000; b++) {
      if (a < neededA || b < neededB) continue;
      res = min(res, solve(0, a, b, dp, packs));
    }
  }

  cout << res << endl;



  return 0;
}
