#include<bits/stdc++.h>
using namespace std;

int k;

char decode(char c, int p){ 
    int s = 3*p+k;
    //cout << c << " "  << p << " " << int(c) << " " << s << endl;
    if (c - s < 'A') {
        return char(c - s + 26);
    }
    return char(int(c) - s);
}

int main() {
    string s;
    cin >> k >> s;

    for (int i = 0; i < s.length(); i++) {
        s[i] = decode(s[i], i+1);
    }
    cout << s;
}