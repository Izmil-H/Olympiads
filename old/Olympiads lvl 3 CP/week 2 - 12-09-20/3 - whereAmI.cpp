#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int k = 1; k < n; ++k) { //length of substrings
        set<string> subs;
        for (int i = 0; i < n-k+1; ++i) { //all possible starting locations
            string sub = "";
            for(int j = 0; j < k; ++j) { //build substring
                sub += s[i+j];
            }
            subs.insert(sub);
        }
        if (subs.size() == n-k+1) {
            cout << k;
            break;
        }
    }
}