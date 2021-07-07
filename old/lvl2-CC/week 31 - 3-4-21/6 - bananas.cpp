#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    while (true) {
        cin >> s;
        if (s == "X") break;
        int a, b; 
        do { 
            a = s.find("ANA"), b = s.find("BAS");
            if (a != string::npos) s.replace(a, 3, "A");
            if (b != string::npos) s.replace(b, 3, "A");

            if (a == string::npos && b == string::npos) break;
        } while(true);
        cout << (s=="A"? "YES": "NO") << endl;
    }
}