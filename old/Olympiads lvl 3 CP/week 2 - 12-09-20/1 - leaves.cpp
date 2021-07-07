#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        string a, b;
        cin >> n >> a >> b; 
        
        string ans = "";
        bool A = false;
        for (int i = 0; i < 2*n; ++i) {
            if (A == true) {
                ans += a.back();
                a.pop_back();
                A = false;
            } else {
                ans += b.back();
                b.pop_back();
                A = true;
            }
        }
        cout << ans << endl;
    }
}