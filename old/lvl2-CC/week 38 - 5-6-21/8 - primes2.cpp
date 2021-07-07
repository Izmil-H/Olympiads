#include<bits/stdc++.h>
using namespace std;

int const LEN = 1e9;
bool prime[LEN+2];

int main() { 
    for (int i = 2; i*i <= LEN; i++) {
        if (!prime[i]) {
            for (int j = 2*i; j <= LEN; j+= i) {
                prime[j] = 1;
            }
        }
    }
    
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        if (!prime[i]) cout << i << endl;
    }
}