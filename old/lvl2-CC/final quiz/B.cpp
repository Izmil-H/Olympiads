#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    map<int,bool> htd;
    for (int i = 0, x; i < n; i++) {cin >> x; htd[x] = 1;}
    
    for (int i = 0; ;i++) {
        if (!htd[x-i]) {
            cout << x-i;
            break;
        }
        if (!htd[x+i]) {
            cout << x+i;
            break;
        }
    }
}