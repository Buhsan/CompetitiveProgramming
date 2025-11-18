#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isEven(int num){
    if (num % 2 == 0) {
        return true;
    } 
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> res;
    for (int i = 0; i < n; i++){
        int s;
        string str ="1";
        cin >> s;
        
        for (int i = 0; i < s-1; ++i) {
            str+="0";
        }
        res.push_back(str);
        
    }
    for(string i : res){
        cout << i << endl;
    }
    return 0;
}