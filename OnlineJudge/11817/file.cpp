#include <bits/stdc++.h>

using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  const double R = 6371009.0;
  while (t--) {
    long double latA, latB, lonA, lonB;
    cin >> latA >> lonA >> latB >> lonB;

    latA = (latA*M_PI)/180.0;
    latB = (latB*M_PI)/180.0;
    lonA = (lonA*M_PI)/180.0;
    lonB = (lonB*M_PI)/180.0;

    long double x1 = R * cosl(latA) * cosl(lonA); 

    long double x2 = R * cosl(latB) * cosl(lonB); 

    long double y1 = R * cosl(latA) * sinl(lonA); 
    long double y2 = R * cosl(latB) * sinl(lonB); 

    long double z1 = R * sinl(latA);
    long double z2 = R * sinl(latB);

    long double difX = fabsl(x2-x1);
    long double difY = fabsl(y2-y1);
    long double difZ = fabsl(z2-z1);

    long double dist1 = sqrtl((difX*difX) + (difY*difY) + (difZ*difZ));

    long double num1 = (x1*x2) + (z1*z2) + (y1*y2);
    long double num2 = R * R;
    long double dist2 = R * acosl(num1/num2);
    cout << llround(fabsl(dist1-dist2)) << endl;

  }

  return 0;
}
