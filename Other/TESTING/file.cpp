#include <iostream>
using namespace std;

#define PRINT(...) ((cout << ... << (__VA_ARGS__, " ")), cout << endl)
// #define PRINT(...) ((cout << ... << (__VA_ARGS__ << " ")), cout << "\n")
template <typename... T>
void cout_var(T& ... args) {(cout <<  ... <<  args)};

int main() {
  int a = 0, b = 1;
    // int a = 42;
    // double b = 3.14;
    // char c = 'x';
    // float d = 2.71f;
    // long e = 100000L;

    cout_var(a,b)
    return 0;
}
