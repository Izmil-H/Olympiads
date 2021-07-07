#include<bits/stdc++.h>
using namespace std;

bool hasFix(string a, string b) {
    if (a.length() < b.length()) return false;
    int aL = a.length(), bL = b.length(); 
    if (a.substr(0, bL).find(b) == string::npos && 
        a.substr(aL-bL, bL).find(b) == string::npos) return false;
    return true;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        if (hasFix(a, b) || hasFix(b, a) ||
            hasFix(a, c) || hasFix(c, a) || 
            hasFix(b, c) || hasFix(c, b) ) { cout << "No\n"; continue; }
        cout << "Yes\n";
    }   
}