#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int sum = 0, mins = INT_MAX;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(') sum++;
        else sum--;
        mins = min(mins, sum);
    }

    if (sum == 0 && mins >= 0) {
        cout << "YES";
    } else if (sum == 2 && mins >= 0) { // flip ( --> )
        cout << "YES";
    } else if (sum == -2 && mins >= -2) { // flip ) --> (
        cout << "YES";
    } else {
        cout << "NO";
    }
}

/*
int main() {
    string s; cin >> s;
    int op = 0, cl = 0;
    bool idk = false;
    for (char c: s) {
        if (c == '(') op++;
        else cl++;
        if (cl > op) idk = true;
    }
    if ( (op == cl && !idk) || 
         (abs(op-cl) != 0 && abs(op-cl)%2 == 0)) cout << "YES";
    else cout << "NO";
}
*/