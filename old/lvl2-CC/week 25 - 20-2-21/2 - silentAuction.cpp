#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string name, winS; int bid, winI = 0;
    for (int i = 0; i < n; i++) {
        cin >> name >> bid;
        if (bid > winI) {
            winS = name;
            winI = bid;
        }
    }
    cout << winS;
}