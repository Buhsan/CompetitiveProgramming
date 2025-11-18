#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node (int val, Node* next) {
    this->val = val;
    this->next = next;
  }
  ~Node() {
    delete this->next;
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int time, num;
  while (cin >> time >> num) {
    vector<int> depth(num + 1), values(num + 1);
    for (int i = 1; i <= num; i++) {
      cin >> depth[i] >> values[i];
    }
    vector<vector<int>> dp(num + 1, vector<int>(time+1));
    for (int i = 1; i <= num; i++) {
      for (int t = 1; t <= time; t++) {
        dp[i][t] = dp[i - 1][t];
        if (t - 3 * depth[i] < 0) continue;
        dp[i][t] = max(dp[i-1][t - 3 * depth[i]] + values[i], dp[i][t]);
      }
    }

    int currPos = num;
    int currTime = time;

    int size = 0;
    Node* root = new Node(0, nullptr);
    Node* curr = root;

    while (currPos != 0) {
      if (dp[currPos][currTime] != dp[currPos - 1][currTime]) {
        curr->next = new Node(currPos, nullptr);
        curr = curr->next;
        currTime -= 3 * depth[currPos];
        size++;
      } 
      currPos--;
    }

    cout << dp[num][time] << '\n' << size << '\n';

    curr = root->next;
    while (curr != nullptr) {
      cout << depth[curr->val] << " " << values[curr->val] << "\n";
      curr = curr->next;
    }
    cout << "----\n";
    delete root;
  }

  return 0;
}
