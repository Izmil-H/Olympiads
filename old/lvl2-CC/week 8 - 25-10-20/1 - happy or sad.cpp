#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int sad = 0, happy = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ':') {
            if (s[i+1] == '-') {
                if (s[i+2] == ')') {
                    happy++;
                } else if (s[i+2] == '('){
                    sad++;
                }
            }
        }
    }
    if (happy > sad) cout << "happy" << endl;
    else if (happy < sad) cout << "sad" << endl;
    else if (happy == 0 && sad == 0) cout << "none" << endl;
    else cout << "unsure" << endl;
}