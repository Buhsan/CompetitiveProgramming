#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> ranges(n);
        vector<int> unique(n, 0); // Output array
        vector<pair<int, int>> events;

        for (int i = 0; i < n; ++i) {
            cin >> ranges[i].first >> ranges[i].second;
            events.emplace_back(ranges[i].first, i + 1);  // Start of range
            events.emplace_back(ranges[i].second + 1, -(i + 1)); // End of range
        }

        sort(events.begin(), events.end());

        set<int> active; // Tracks active ranges
        for (auto &[pos, id] : events) {
            if (id > 0) {
                active.insert(id - 1);
            } else {
                active.erase(-id - 1);
            }

            if (id > 0 && active.size() == 1) {
                unique[*active.begin()] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << unique[i];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}