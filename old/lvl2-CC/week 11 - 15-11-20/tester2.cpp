#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "";
    int n = 100000;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) s+= '1';
        else s+= '0';
    }
    
    int opr = 0;
    int count = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '1')  {
            cout << i << " ";
            count++;
            for (int j = i; j >= 0; j--) {
                opr++;
                if (s[j] == '1') s[j] = '0';
                else s[j] = '1';
            }
        }   
    }
    cout << endl << count  << " " << opr << endl;
}