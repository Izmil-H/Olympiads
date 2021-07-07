#include<bits/stdc++.h>
using namespace std;

const int len = 2e6 + 1;
bool prime[len] = {0};

int main() {
    for (int i = 2; i <= len; i++) {
        if (!prime[i]) {
            for (int j = i+i; j <= len; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 2; i <= n; i++) {
            if (!prime[i] && !prime[2*n-i]) {
                cout << i << " " << 2*n - i << endl;
                break;
            }
        } 
    }
}