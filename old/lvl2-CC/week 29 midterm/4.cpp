#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x[n], y[n], w[n], h[n], px, py, p = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i] >> h[i];
    }
    cin >> px >> py;
    for (int i = 0; i < n; i++) {
        if (x[i] <= px && y[i] <= py && x[i]+w[i] >= px && y[i]+h[i] >= py) {
            p = i+1;
        }
    }
    if (!p) cout << -1;
    else cout << p;
}