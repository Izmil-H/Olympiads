#include<bits/stdc++.h>
using namespace std;

int main() {
    string alph, s;
    cin >> alph >> s;
    int idx[26];
    for (int i = 0; i < 26; i++) {
        idx[alph[i] - 'a'] = i;
    }
    int val[26] = {0};
    for (int i = 1; i < s.length(); i++){
        if (idx[s[i]-'a'] <= idx[s[i-1]-'a']) {
            val[s[i] - 'a']++;
        }
    }
    int ans = 1;
    for (int i = 0; i < 26; i++) {
        ans += val[i];
    }
    cout << ans;
}