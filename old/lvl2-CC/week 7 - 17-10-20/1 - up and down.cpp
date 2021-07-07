#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, s;
    cin >> a >> b >> c >> d >> s;
    
    int ni = s/(a+b) * (a-b);
    //cout << "n: " << ni << endl; 
    for (int i = 1; i <= s%(a+b); ++i) {
        if (i <= a) ni++;
        else ni--;
        //cout << i << ":" << ni << endl;
    }

    int by = s/(c+d) * (c-d);
    //cout << "b: " << by << endl;
    for (int i = 1; i <= s%(c+d); ++i) {
        if (i <= c) by++;
        else by--;
        //cout << i << ":" << by << endl;
    } 

    if (ni > by) cout << "Nikky" << endl;
    else if (by > ni) cout << "Byron" << endl;
    else cout << "Tie" << endl;
}