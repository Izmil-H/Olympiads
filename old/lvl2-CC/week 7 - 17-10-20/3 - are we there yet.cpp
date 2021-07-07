#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[5];
    for (int i = 1; i <= 4; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int dist = 0;
            for (int k = min(i, j); k < max(i, j); k++) {
                dist += arr[k];
            }
            cout << dist << " ";
        }
        cout << endl;
    }
}