#include<bits/stdc++.h>
using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";
string s;

vector<string> idk;

bool comp(string a, string b) {
    if (a.length() < b.length()) return true;
    if (a.length() == b.length() && a.compare(b) < 0) return true;
    return false;
}

int main() {
    cin >> s;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        
    }
}