#include<bits/stdc++.h>
using namespace std;

char shift(char c, int n) {
    if ( (int(c) + n)-'A' > 25) {
        return char(c+n-26);
    }
    return char(c + n);
}

int main() {
    string key, s;
    cin >> key; cin.ignore();
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        if (!isalpha(s[i])) {
            s.erase(i,1);
            i--;
        } else {
            s[i] = shift(s[i], key[i%key.length()]-'A');
        }
    }
    cout << s;
}