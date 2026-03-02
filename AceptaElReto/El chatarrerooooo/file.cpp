#include <bits/stdc++.h>
using namespace std;


double calc(const vector<int> &x, const vector<int> & y) {
  int n = x.size();
  int j = n-1;
  double area = 0.0;
  for (int i = 0; i < n; i++) {
    area += (x[j]+x[i])* (y[j]-y[i]);
    j = i;
  }
  return (area/2.0);
}

string print(double sol) {
  // ostringstream oss;
  // oss << fixed << setprecision(6) << sol;
  // string res = oss.str();

  string res = to_string(sol);
  res.erase(res.find_last_not_of('0') + 1, std::string::npos);
  if (res.back() == '.') {
    res.pop_back();
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
      int p; cin >> p;
      vector<int> x(p),y(p);
      for (int j = 0; j < p; j++) {
        cin >> x[j] >> y[j];
      }
      area += abs(calc(x,y));
    }
    cout << print(area) << endl;
  }


  return 0;
}
