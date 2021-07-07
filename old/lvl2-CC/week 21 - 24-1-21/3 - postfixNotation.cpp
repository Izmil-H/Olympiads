#include<bits/stdc++.h>
using namespace std;

int main() {
    string nonNum = "+-*/%^";
    stack<double> stk;
    string l; getline(cin, l);
    
    while (true) {
        string s;
        if (l.length() == 1){
            s = l;
            l = "";
        }
        else{
            s = l.substr(0,l.find(" "));
            l.erase(0,l.find(" ")+1);
        }
        
        if (nonNum.find(s[0]) != string::npos) {
            double b = stk.top(); stk.pop();
            double a = stk.top(); stk.pop();
            if (s == "+") stk.push(a+b);
            else if (s == "-") stk.push(a-b);
            else if (s == "*") stk.push(a*b);
            else if (s == "/") stk.push(a/b);
            else if (s == "%") stk.push(int(a)%int(b));
            else if (s == "^") stk.push(pow(a, b));
        } else {
            stk.push(double(stoi(s)));
        }

        if (l.length() < 1) {
            cout << fixed << setprecision(1) << stk.top();
            break;
        }
    }
}