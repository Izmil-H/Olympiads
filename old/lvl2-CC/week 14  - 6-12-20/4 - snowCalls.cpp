#include<bits/stdc++.h>
using namespace std;

int main() {
    char alph[26] = {'2','2','2', '3','3','3', '4','4','4', '5','5','5', '6','6','6', '7','7','7','7', '8','8','8', '9','9','9','9'};
    int n; cin >> n; 
    for (int t = 0; t < n; t++) {
        string s; cin >> s;
        string num = "";
        for (int i = 0; ; i++) {
            //cout << s[i] <<" ";
            if (s[i] == '-') {
                continue;
            } else if (int(s[i]) - '0' <= 9) {
                num += s[i];
                //cout << "num";
            } else {
                num += alph[s[i]-'A'];
                //cout << " " << alph[s[i]-'A'];
            }
            //cout << " " << num.length() << endl;
            if (num.length() == 10) break;
        }
        num.insert(3, 1, '-'); num.insert(7, 1, '-'); 
        cout << num << endl;
    }
}