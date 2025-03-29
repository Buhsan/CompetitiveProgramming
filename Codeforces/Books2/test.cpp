#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Prefix sum array to store cumulative time up to each book
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    int max_books = 0;
    int start = 0;

    for (int end = 1; end <= n; ++end) {
        // Check if the sum of books from start to end fits in time t
        while (prefix_sum[end] - prefix_sum[start] > t) {
            ++start;
        }
        // Update the maximum books that can be read
        max_books = max(max_books, end - start);
    }

    cout << max_books << endl;

    return 0;
}
