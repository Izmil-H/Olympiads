#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "";
    string alph[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444",
                       "5", "55", "555", "6", "66", "666", "7", "77", "777", 
                       "7777", "8", "88", "888", "9", "99", "999", "9999"};
    cin >> s;
    while (s != "halt") {
        string ans = "-";
        int time = 0;
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (alph[idx][0] == ans.back()) {
                ans += "pp";
            }
            ans += alph[idx];
        }
        cout << ans.length() - 1 << endl;
        cin >> s;
    }
}