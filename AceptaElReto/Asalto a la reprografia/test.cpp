#include <iostream>
#include <string>

// Function to find the smallest repeating pattern
std::string findPattern(const std::string& sequence) {
    int n = sequence.size();
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len == 0) {
            std::string pattern = sequence.substr(0, len);
            bool matches = true;
            for (int i = 0; i < n; i += len) {
                if (sequence.substr(i, len) != pattern) {
                    matches = false;
                    break;
                }
            }
            if (matches) {
                return pattern;
            }
        }
    }
    return sequence;
}

int main() {
    std::string sequence;
    std::cin >> sequence;

    // Find the repeating pattern
    std::string pattern = findPattern(sequence);
    std::cout << "Identified pattern: " << pattern << std::endl;

    // Predict the next number in the sequence
    std::cout << "Next number in the sequence: ";
    std::cout << pattern << std::endl;

    return 0;
}
