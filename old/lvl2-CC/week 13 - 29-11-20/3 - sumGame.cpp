#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int swift[n]; 
    int sema[n];
    for (int i = 0; i < n; ++i) cin >> swift[i];
    for (int i = 0; i < n; ++i) cin >> sema[i];

    int swiftSum = 0, semaSum = 0, large = 0;
    for (int i = 0; i < n; ++i) {
        swiftSum += swift[i];
        semaSum += sema[i];
        if (swiftSum == semaSum) large = max(large, i+1);
    }
    cout << large;
}