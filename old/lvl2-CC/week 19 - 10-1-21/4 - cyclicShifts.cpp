#include<bits/stdc++.h>
using namespace std;

int main() {
    string t, s;
    cin >> t >> s;
    for (int i = 0; i < s.length(); i++) {
        s += s[0]; s.erase(0,1);
        cout << s << endl;
        if (t.find(s) != string::npos) {
            cout << "yes";
            break;
        }
        if (i == s.length()-1) cout << "no";
    }
}