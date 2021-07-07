#include<bits/stdc++.h>
using namespace std;

/* -- MY IDEA -- 
int main() {
    int n; string s;
    cin >> n >> s;
    set<char, greater<char>> unq;
    int most = 0;
    for(int i = 0; i < n-1; i++) {
        unq.insert(s[i]);
        int count = 0; 
        for (auto it: unq){
            //cout << i << " " << it << " " << count << " ";
            if (s.find(it, i+1) != string::npos) {
                count++; 
                //cout << 't';
            }
            //cout << endl;
        }
        most = max(most, count);
    }
    cout << most;
}
*/
// -- BETTER IDEA -- 
int main() {
    int n; string s;
    cin >> n >> s;
    int s1[26] = {0}, s2[26] = {0};
    for (char x: s) {
        s2[x-'a']++;
    }
    int most = 0, count = 0;
    for(char x: s){
        s1[x-'a']++; s2[x-'a']--;
        if (s1[x-'a'] > 0 && s2[x-'a'] > 0) count++;
        most = max(most, count);
    }
    cout << most;
}