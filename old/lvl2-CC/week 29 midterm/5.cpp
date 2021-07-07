#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bool arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n; i++) { //start
        for (int j = 0; j < n; j++) { //len
            bool cur = arr[i];
            for (int k = i+1; k < n; k++) {
                if (cur != arr[])
            }
        }
    }
    cout << ans;
}