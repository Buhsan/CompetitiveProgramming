#include <iostream>
 
using namespace std;
 
int main()
{
    int n, n1, n2;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        cout << a*2 << " ";
    }
    cout<<endl;
    cin >> n1;
    for(int i=0; i<n1; i++) {
        char c;
        cin >> c;
        cout << (char)toupper(c) << " ";
    }
    cout<<endl;
    cin >> n2;
    for(int i=0; i<n2; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.size(); j++){
            char b = (char)tolower(s[j]);
            if(b == 'a' || b == 'e'||b == 'u'||b == 'o' || b == 'i') {s[j] = '0';}
        }
        cout << s << " ";
    }
    cout<<endl;
    return 0;
}