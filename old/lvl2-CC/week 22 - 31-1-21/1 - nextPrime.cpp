#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) n = 2;
    for (int i = n; ; i++) {
        bool prime = true;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << i;
            break;
        }
    }
}