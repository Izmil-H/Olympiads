#include<bits/stdc++.h>
using namespace std;

long long gcd(int a, int b) {
    if (a == 0) return b;
    gcd(b%a, a);
}

int main() {
    int n; cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int gd = arr[0];
    for (int i = 1; i < n; i++) {
        gd = gcd(gd, arr[i]);
    }
    int lp;
    for (int i = 2; i*i <= gd; i++) {
        while (gd % i == 0) {   
            gd /= i;
        }
        lp = i;
    }
    if (gd != 1) lp = gd;
    if (lp > 0) cout << gd;
    else cout << "DNE";
    cout << endl;
}

