#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        stack<char> stk;
        bool valid = true;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            if (c == ')') {
                if (stk.size() && stk.top() == '(') stk.pop();
                else valid = false;
            } else if (c == ']') {
                if (stk.size() && stk.top() == '[') stk.pop();
                else valid = false;
            } else if (c == '}') {
                if (stk.size() && stk.top() == '{') stk.pop();
                else valid = false;
            }
        }
        if (valid) cout << "balanced\n";
        else cout << "not balanced\n";
    }
}