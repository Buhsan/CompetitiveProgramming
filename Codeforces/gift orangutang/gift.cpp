#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> res;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        vector<int> c;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end(), [] (int a, int b) {return a>b;});
        int max = *max_element(a.begin(), a.end());
        a.erase(a.begin());
        sort(a.begin(), a.end(), [] (int a, int b) {return a<b;});
        a.insert(a.begin(), max);
        auto end = a.begin();
        end +=1;
        for (int i = 0; i < n; i++){
            b.push_back(*min_element(a.begin(), end));
            c.push_back(*max_element(a.begin(), end));
            end += 1;
        }
        int result = 0;
        for (int i = 0; i < n; i++){
            result += (c[i] - b[i]);
        }
        res.push_back(result);
    }
    for(int i : res){
        cout << i << endl;
    }

    return 0;
}