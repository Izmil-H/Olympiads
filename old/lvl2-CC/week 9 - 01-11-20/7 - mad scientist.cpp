#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    string s;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) s += tolower(b[i]);
        else s += b[i];
    }
    cout << s << endl;
    for (int i = 1; i < n-1; ++i) {
        if (s[i] == 'h' || s[i] == 'g') {
            if (s[i-1] == toupper(s[i]) && s[i+1] == toupper(s[i])) s[i] == toupper(s[i]);
        }
    }
    cout << s << endl;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'h' || s[i] == 'g') s.erase(i, 1);
    }
    cout << s << endl;
    int cnt = 1;
    for (int i = 0; i < s.length(); ++i) {
        if ()
    }
}