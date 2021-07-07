#include<bits/stdc++.h>
using namespace std;

int main() {
    while (true) { 
        int n; cin >> n;
        if (n == 0) break;

        int arr[n], dif[n-1]; 
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }        
        
        if (n == 1) {
            cout << 1 << endl;
        } else {            
            for (int i = 0; i < n-1; i++) { 
                dif[i] = arr[i+1] - arr[i];
            }
            int i = 1;
            for (i = 1; i < n-1; i++) { // size
                if (dif[i] != dif[0]) continue;
                bool works = true;
                for (int j = 0; j < n-1; j++) { // check
                    if (dif[j] != dif[j%i]) works = false;
                }
                if (works) break;
            }
            cout << i << endl;
        }
    }
}