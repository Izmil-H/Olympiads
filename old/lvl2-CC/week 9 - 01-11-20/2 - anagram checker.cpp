#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int freq1[26] = {0};
    int freq2[26] = {0};
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != ' ') freq1[s1[i] - 'A']++;
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] != ' ') freq2[s2[i] - 'A']++;
    }     

    for (int i = 0; i < 26; ++i) {
        //cout << freq1[i] << " " << freq2[i] << endl; 
        if (freq1[i] != freq2[i]) {
            cout << "Is not an anagram.";
            break;
        }
        if (i == 25) cout << "Is an anagram.";
    }
}