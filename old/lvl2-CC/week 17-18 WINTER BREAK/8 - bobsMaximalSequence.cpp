#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long a[n];
    for (int i = 0; i < n-1; i++) {
        int b; cin >> b;
        if (i == 0) a[0] = b;
        a[i+1] = b;
        if (b < a[i]) {
            a[i] = b;
        }
        //for (int j = 0; j < n; j++) cout << a[j] << " "; cout << endl;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << sum;
}