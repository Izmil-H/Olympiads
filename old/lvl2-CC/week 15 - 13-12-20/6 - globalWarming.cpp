#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        int arr[n], dif[n-1];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 1; i < n; i++) dif[i-1] = arr[i]-arr[i-1];

        for (int i = 1; i < n-1; i++) { //length
            bool cycle = true;
            for (int j = i; j < n-1; j+=i) { //where
                for (int k = 0; k < i && j+k < n-1; k++) {

                    if (dif[k] != dif[k+j]) cycle = false;
                }
            }
            if (cycle) {
                cout << i << endl;
                break;
            }
            if (i == n-2) cout << n-1 << endl;
        }
    }
}