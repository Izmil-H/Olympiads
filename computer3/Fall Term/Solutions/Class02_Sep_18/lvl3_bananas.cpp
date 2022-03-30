#include <bits/stdc++.h>
using namespace std;
string s;
bool isAWord(string s);
bool isMonkeyWord(string s){
    if(s.empty()) return false;
    if(isAWord(s)) return true;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'N' && isAWord(s.substr(0, i)) && isMonkeyWord(s.substr(i+1)))
            return true;
    }
    return false;
}
bool isAWord(string s) {
    if(s.empty()) return false;
    if(s == "A") return true;
    if(s.size()>=3 && s[0] == 'B' && s.back() == 'S' && isMonkeyWord(s.substr(1, s.size()-2)))
        return true;
    return false;
}
int main(){
    while(cin >> s && s != "X") {
        cout << (isMonkeyWord(s) ? "YES\n" : "NO\n");
    }
}