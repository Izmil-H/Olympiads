#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    map<char,int> mp;
    for (auto c: s){
        mp[c]++;
    }
    int Lm = 0, Ls = 0, Ml = 0, Ms = 0;
    for (int i = 0; i < mp['L']; i++) {
        if (s[i] == 'S') Ls++;
        else if (s[i] == 'M') Lm++;
    }
    for (int i = mp['L']; i < mp['L'] + mp['M']; i++) {
        if (s[i] == 'S') Ms++;
        else if (s[i] == 'L') Ml++;
    }
    cout << (Ls + Lm) + (Ms + Ml) - min(Lm, Ml);
}