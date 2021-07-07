#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    long sumArr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sumArr[0] = arr[0];
        sumArr[i] = sumArr[i-1] + arr[i];
    }
    int q; cin >> q;
    int qu[q][2];
    for (int i = 0; i < q; ++i) {
        cin >> qu[i][0] >> qu[i][1];
        cout << sumArr[qu[i][1]] - sumArr[qu[i][0]] + arr[qu[i][0]] << endl;
    }
}