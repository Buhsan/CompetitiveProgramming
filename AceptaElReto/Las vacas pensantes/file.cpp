#include <bits/stdc++.h>

using namespace std;

// dp[start][end] = max food until this state


int solve(int start, int end, vector<int> &food, vector<vector<int>> &dp) {
  //cout << "start: " << start << " end: " << end << endl;
  int n = food.size();
  if (start > end) {
    //cout << "quit" << endl;
    return 0;
  }
  if (dp[start][end] != -1) return dp[start][end];
  //take start or take end?


  //chosing start: need to calculate which pointer to move for anoter cow
  {
    //cout << "choosing start with " << start << " " << end << endl;
    int res = food[start];
    if (start+1 < n && food[start+1] >= food[end]) { // choosing start 2 times
      //cout << "other cow chose start" << endl;
      res += (start+2 <= end) ? solve(start+2,end, food, dp) : 0;
      //dp[start+1][end] = res;
    } else { // choosing start for ourselfs and end for other cow
      //cout << "other cow chose end" << endl;
      res += (start+1 <= end-1) ? solve(start+1, end-1, food, dp) : 0;
      //dp[start+1][end] = res;
    }
    dp[start][end] = max(dp[start][end], res);
  }

  //chosing end: need to calculate which pointer to move for another cow
  {
    //cout << "choosing end with " << start << " " << end << endl;
    int res = food[end];
    if (end-1 >= 0 && food[start] >= food[end-1]) { // choosing end 2 times
      //cout << "other cow chose start" << endl;
      res += (start+1 <= end-1) ? solve(start+1,end-1, food, dp) : 0;
      //dp[start][end-1] = res;
    } else { // choosing end for ourselfs and start for other cow
      //cout << "other cow chose end" << endl;
      res += (start <= end-2) ? solve(start, end-2, food, dp) : 0;
      //dp[start][end-1] = res;
    }
    dp[start][end] = max(dp[start][end], res);
  }

  return dp[start][end];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  while (cin >> n && n) {
    vector<int> food(n);
    vector<vector<int>> dp (n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) cin >> food[i];
    cout << solve(0, n-1, food, dp) << '\n';
  }

  return 0;
}
