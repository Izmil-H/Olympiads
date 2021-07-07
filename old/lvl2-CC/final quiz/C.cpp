#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    bool ans = false;
    for (int i = 0; i < a.length(); i++) {
        string tmp = a;
        tmp.erase(i,1);
        if (tmp == b) {ans = true; break;}
    }
    if (ans || a == b) cout << "Yes";
    else cout << "No";
}