#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<string> line;
    while (cin >> s) {
        if (s[0] != '(' && s[0] != ')' && s[0] != ' ') line.push_back(s);
    }

    for (auto it = line.rbegin(); it != line.rend(); it++) {
        cout << *it << endl;
    }

}



/*
int cnt = 0;

int op(char o, int a, int b){ 
    if (o == '+') return a + b;
    if (o == '-') return a - b;
    if (o == '*') return a * b;
    if (o == 'q') return a / b;
    if (o =='r') return a % b;
}

int solve(string s) {
    cnt++;
    if (s.length() == 1) {
        return s[0]-'0';
    }
    int idx, sum = 0;
    for (int i = 3; i < s.length()-1; i++) {
        if (s[i] != ' ') {
            if (s[i] == '(') sum++;
            else if (s[i] == ')') sum--;
            if (sum == 0){
                idx = i;
                break;
            }
        }
    }
    //cout << cnt << ": " << s.substr(3,idx-2) << "   |   " << s.substr(idx+2, s.length()-idx-3) << endl;
    return op(s[1], solve(s.substr(3,idx-2)), solve(s.substr(idx+2, s.length()-idx-3)));
}

int main() {
    int n = 10;
    while (n--) {
        string s; 
        getline(cin, s);
        cin.clear();
        cout << solve(s) << endl;
    }   
}
*/