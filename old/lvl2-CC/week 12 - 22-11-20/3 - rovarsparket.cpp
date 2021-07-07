#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    //             a b c d e f g h i j k l  m  n  o  p  q  r  s  t  u  v  w  x  y  z 
    int vow[26] = {0,0,0,4,4,4,4,8,8,8,8,8,14,14,14,14,14,14,20,20,20,20,20,20,20,20};
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        int idx = s[i]-'a';
        ans += s[i];
        if (idx != vow[idx]) {
            ans += alph[vow[idx]];
            if (s[i] == 'z') ans += 'z';
            else if (idx+1 == vow[idx+1]) ans += alph[idx+2]; 
            else ans += alph[idx+1];
        }
    }
    cout << ans;
}