#include<bits/stdc++.h>
using namespace std;

int main() {
    string shortForm[12] = {"CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "TY", "TTYL"};
    string longForm[12] = {"see you", "I'm happy", "I'm unhappy", "wink", "stick you my tongue", "sleepy", "totally awesome", "Canadian Computing Competition", "because", "thank-you", "you're welcome", "talk to you later"};
    
    bool idk = true;
    while (idk) {
        string s;
        cin >> s;
        for (int i = 0; i < 12; ++i) {
            if (s == shortForm[i]) {
                cout << longForm[i] << endl;
                if (i == 11) idk = false;
                break;
            }
            if (i == 11) cout << s << endl;
        }
    }
}