#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin>>n && n) {
    int a;
    int totalSeg = 0;
    while (cin >> a && a) {
      totalSeg += (n*a);
    }

    int seg = totalSeg % 60;
    int min = (totalSeg / 60) % 60;
    int hours = totalSeg / 3600;

    string s = (seg <= 9 ? "0" + to_string(seg) : to_string(seg));
    string m = (min <= 9 ? "0" + to_string(min) : to_string(min));
    string h = (hours <= 9 ? "0" + to_string(hours) : to_string(hours));
    cout << h << ":" << m << ":" << s<< '\n';
  }
  return 0;
}
