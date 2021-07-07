#include<bits/stdc++.h>
using namespace std;

const int len = 1e7;
int prmcty[len+1];

int primacity(int n) { 
    int n2 = n, ans = 0;
    for (int i = 2; i*i <= n2; i++) {
        if (n%i == 0) ans++;
        while (n%i == 0) {
            n /= i;
        }
    }
    return ans;    
}

int main() {
    for (int i = 2; i < len; i++) {
        prmcty[i] = primacity(i);
    }
    for (int i = 0; i < 100; i++) {
        cout << prmcty[i] << " ";
    }
}