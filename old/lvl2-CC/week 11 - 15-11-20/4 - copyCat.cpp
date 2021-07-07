#include<bits/stdc++.h>
using namespace std;

int main() {
    for (int t = 0; t < 5; t++){
        string s;
        getline(cin, s);
        int n = s.length();
        int size = 0;
        for (int i = 1; i < n; ++i) {
            if (s.substr(0, i) == s.substr(n-i, i)) {
                size = i;
                //cout << "# ";
            }
            //cout << s.substr(0, i) << " " << s.substr(n-i, i) << ": " << size << endl;
        }
        //cout << endl;
        
        string s2 = s;
        s2 = s2.erase(0, size);
        //cout << "cnt: " << size << endl << s2 << endl;
        
        if (size < s.length() ) cout << s << s2;
        else cout << s << s;
        cout << endl;
        //cout << "-------" << endl;
    }
}