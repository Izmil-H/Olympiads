#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, last = "";
    while (true) {
        cin >> s;
        if (s == "99999") break;

        int n = s[0] + s[1] - 2*int('0');
        if (n == 0) {
            cout << last << s.substr(2);
        } else if (n%2 == 0) {
            cout << "right " << s.substr(2);
            last = "right ";
        } else {
            cout << "left " << s.substr(2);
            last = "left ";
        }
        cout << endl;
    }
}