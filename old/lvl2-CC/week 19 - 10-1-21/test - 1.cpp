#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
    
    if (s.substr(0,5) == "darcy") {
        int cnt = 0, cnt2 =0;
        for (int i = 5; i < s.length()-3; i++) {
            if (s[i] == '_') cnt++;
            else cnt2++;
        }
        if (s.substr(s.length()-3, 3) == "liu" && cnt2 == 0) {
            if (cnt == 1) cout << "real";
            else cout << "fake";
        } else cout << "other user";
    } else cout << "other user";
}