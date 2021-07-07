#include<bits/stdc++.h>
using namespace std;

int main() {
    int w;
    cin >> w;
    int n, m;
    n = ceil(sqrt(w))+1;
    m = n - 1;
    int values[n];
    values[0] = -1;
    cout << n+1 << " " << m << endl;
    for (int i = 1; i < n; ++i) {
        cout << 1 << " " << i + 1 << "  " << i << ":" << w;
        if (i == n-1) {
            values[i] = w;
            break;
        }
        if (w-n > n-i-1) {
            w -= n;
            values[i] = n;
        } else {
            w -= 1;
            values[i] = 1;
        } 
        cout << "-" << w <<  endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << values[i] << " ";
    }
}