#include<bits/stdc++.h>
using namespace std;

long long n;
long ans = 0;
void comb(string s) {
    if (stoll(s) > n) return;
    if (s.length() > 1) ans++;
    comb(s+'2');
    comb(s+'3');
}

int main() {
    cin >> n;
    comb("0");
    cout << ans;
}