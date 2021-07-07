#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    int arr[n];
    int sumArr[n] ={0};
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sumArr[i] = sum + arr[i];
        sum += arr[i];
    }
    int small = INT_MAX;
    int idx;
    for (int i = 0; i < n; ++i) {
        int diff = abs(sumArr[i] - (sumArr[n-1] - sumArr[i]));
        if (diff < small) {
            small = diff;
            idx = i;
        }
    }
    cout << small;
}