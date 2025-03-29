#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
using namespace std;


int main()
{
    int n, t;
    int newT = 0, i = 0;
    // int num = 0;
    cin >> n >> t;
    int maxBooks = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    // sort(a.begin(), a.end(), [] (int a, int b) {return a<b;});

    // for(int i : a){
    //     cout << i << endl;
    // }
    

    for (int j = 0; j < n; j++){
        newT += a[j];
        while (newT > t)
        {
            newT -= a[i];
            i++;
        }
        maxBooks = max(maxBooks, j - i + 1);
        
    }
    cout << maxBooks;
    return 0;
}

