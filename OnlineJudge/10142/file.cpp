#include <bits/stdc++.h>

using namespace std;

struct Candidate {
  int id;
  int votes;
  string name;
  bool eliminated;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  string temp;
  getline(cin, temp); 
  getline(cin, temp); 

  for (int tt = 0; tt < t; tt++) {
    int n;
    cin >> n;

    string temp;
    getline(cin, temp);

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; i++) {
      candidates[i].id = i;
      candidates[i].votes = 0;
      candidates[i].eliminated = false;
      getline(cin, candidates[i].name);
    }

    vector<vector<int>> ballots;
    string vote;

    while (getline(cin, vote) && !vote.empty()) {
      stringstream ss(vote);
      vector<int> ballot;
      int a;
      while (ss >> a) {
        ballot.push_back(a - 1);
      }
      ballots.push_back(ballot);
    }

    if (tt > 0) cout << '\n';

    int total_ballots = ballots.size();

    while (true) {
      for (int i = 0; i < n; i++) {
        candidates[i].votes = 0;
      }

      // recounting
      for (vector<int> ballot : ballots) {
        for (int candidate_idx : ballot) {
          if (!candidates[candidate_idx].eliminated) {
            candidates[candidate_idx].votes++;
            break;
          }
        }
      }

      int max_votes = -1;
      int min_votes = INT_MAX;

      for (int i = 0; i < n; i++) {
        if (!candidates[i].eliminated) {
          if (candidates[i].votes > max_votes) max_votes = candidates[i].votes;
          if (candidates[i].votes < min_votes) min_votes = candidates[i].votes;
        }
      }

      // winner case
      if (max_votes * 2 > total_ballots) {
        for (int i = 0; i < n; i++) {
          if (!candidates[i].eliminated && candidates[i].votes == max_votes) {
            cout << candidates[i].name << endl;
          }
        }
        break;
      }

      //tie case
      if (min_votes == max_votes) {
        for (int i = 0; i < n; i++) {
          if (!candidates[i].eliminated) {
            cout << candidates[i].name << endl;
          }
        }
        break;
      }

      // deleting the lowest score
      for (int i = 0; i < n; i++) {
        if (!candidates[i].eliminated && candidates[i].votes == min_votes) {
          candidates[i].eliminated = true;
        }
      }
    }
  }

  return 0;
}
