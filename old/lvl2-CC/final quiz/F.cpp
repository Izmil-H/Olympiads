#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n], scrs[n] = {0};
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (arr[i]%arr[j] == 0) scrs[i]++;
        }  
    }
    for (auto x: scrs) cout << x << "\n";
}