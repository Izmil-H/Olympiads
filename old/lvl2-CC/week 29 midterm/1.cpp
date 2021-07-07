#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b, a2, b2;
    cin >> a >> b;
    a2 = a; b2 = b;
    reverse(a2.begin(), a2.end());
    reverse(b2.begin(), b2.end());

    if (a2 < b2) cout << stoll(a2);
    else cout << stoll(b2);
}