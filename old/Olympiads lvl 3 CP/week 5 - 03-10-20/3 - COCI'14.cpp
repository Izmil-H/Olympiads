#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> freq;
    for (int i = 0; i < n; ++i) {
        string s; 
        cin >> s;
        freq[s]++;
    }
    for (int i = 0; i < n-1; ++i) {
        string s; 
        cin >> s;
        freq[s]--;
    }
    for (map<string,int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        if (it->second == 1) {
            cout << it->first;
        }
    }
}