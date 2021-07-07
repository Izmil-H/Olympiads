#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    while (s[0] != 'X') { 
        int ind[2] = {0, s.length()};
        bool word = true;
        if (s[0] == 'B') {
            if (s[s.length()-1] == 'S') {
                ind[0] = 1;
                ind[1] -= 1;
            } else {
                word = false;
            }
        }
    
        bool A = true;
        for (int i = ind[0]; i < ind[1]; ++i) {
            if (A == true)  {
                if (s[i] == 'A') {
                    A = false;
                } else {
                    word = false;
                    break;
                }
            } else {
                if (s[i] == 'N') {
                    A = true;
                } else {
                    word = false;
                    break;
                }
            }
        }
        if (word) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
        cin >> s;
        //****************************************************************
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'N') {
                if (s[i-1] == 'A') {
                    if (s[i+1] != 'A') {
                        word = false;
                    }
                } else if (s[i-1] == 'S') {
                    if (s[i+1] != 'B') {
                        word = false;
                    }
                }
            }
        }


    }
}