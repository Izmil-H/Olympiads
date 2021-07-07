#include<bits/stdc++.h>
using namespace std; 

int main() {
    string s;
    cin >> s;
    int alph[26] ={0};
    for (int i = 0; i < s.length(); ++i) {
        alph[s[i]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (alph[i] % 2 != 0) {
            cout << "NO";
            break;
        }
        if (i == 25) cout << "YES";
    }
}