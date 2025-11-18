#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




int main(){
    int x = 0, y = 0;
    int turn = 1;
    int paso = 0;
    vector<int> a(2);
    cin >> a[0] >> a[1];

    if (a[0] == 0 && a[1] == 0){
        cout << 0;
        return 0;
    }
    else if (a[0] == 1 && a[1] == 0){
        cout << 0;
        return 0;
    }

    bool res = false;
    vector<int> next = {1,1};

    while(next != a){
        bool equals = false;
        paso = 0;
        x++;
        y++;
        // turn++;
        vector<vector<int>> nextTurn= {{-x,y}, {-x,-y}, {x+1,-y}, {x+1, y+1}};
        // cout << next[0] << " " << next[1] << endl;
        

        if (paso == 0 && !equals){
            while(next != nextTurn[paso]){
                next[0]--;
                // cout << "paso 0: " <<next[0] << " " << next[1] << endl;
                if (next == a){
                    equals = true;
                    paso--;
                    break;
                }
            }
            turn++;
            // cout << "turn: " << turn << endl;
            paso++;
        }
        if (paso == 1 && !equals){
            while(next != nextTurn[paso]){
                next[1]--;
                // cout << "paso 1: " <<next[0] << " " << next[1] << endl;
                if (next == a){
                    equals = true;
                    paso--;
                    break;
                }
            }
            turn++;
            // cout << "turn: " << turn << endl;
            paso++;
        }
        if (paso == 2 && !equals){
            while(next != nextTurn[paso]){
                next[0]++;
                // cout << "paso 2: " <<next[0] << " " << next[1] << endl;
                if (next == a){
                    equals = true;
                    paso--;
                    break;
                }
            }
            turn++;
            // cout << "turn: " << turn << endl;
            paso++;
        }
        if (paso == 3 && !equals){
            while(next != nextTurn[paso]){
                next[1]++;
                // cout << "paso 3: " <<next[0] << " " << next[1] << endl;
                if (next == a){
                    equals = true;
                    paso--;
                    break;
                }
            }
            paso = 0;
            turn++;
            // cout << "turn: " << turn << endl;
        }
    }

    cout << turn;
    return 0;
}