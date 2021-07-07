#include<bits/stdc++.h>
using namespace std;

// ------ WITH STACK -------
int main() {
    int n; cin >>n;
    while (n--) {
        string s; cin >> s;
        stack<char> stk; bool valid = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') stk.push(s[i]);
            else if (s[i] == ')'){
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else {valid = false; break;}
            }
        }
        if (valid && stk.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    
}

/*
int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int opn = 0, cls = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') opn++;
            else if (s[i] == ')') cls++;
            if (cls > opn) {
                cout << "NO";
                break;
            }
            if (i == s.length()-1) {
                if (opn == cls) cout << "YES";
                else cout << "NO";
            }
        }
        cout << endl;
    }
}
*/