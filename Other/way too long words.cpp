#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
    int num;
    cin >> num;
    list <string> list1;
    for (int i = 0; i < num; i++){
        string a;
        cin >> a;
        int b = a.length();
        if (b > 10){
            list1.push_back(a.substr(0,0) + to_string(b-2) +  a.substr(b-1,b-1));
            //iter++;
        }
        else {list1.push_back(a);}
    }

    for (string i : list1){
        cout << i << "\n";
    }
    
    return 0;
}