#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x = n;
    for (int i = 0; i < n; i++) {
        x += n;
    }
    cout << x;
}