#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int count = 1;    
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) count++;
    }
    if (s[n-1] == '0') count--;
    cout << count;
}

    /*
    int n; cin >> n;
    string s; cin >> s;
    int count = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1')  {
            count++;
            for (int j = i; j >= 0; j--) {
                if (s[j] == '1') s[j] = '0';
                else s[j] = '1';
            }
        }   
    }
    cout << count;
    */   