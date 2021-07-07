#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int arr[n];

    int sumArr[n] = {0};
    sumArr[0] = arr[0];
    for (int i = 0; i < n; ++i) {
        sumArr[i] = sumArr[i-1] + arr[i];
    }

    // 1 2 3 4 5 6 7 8 9 10
    // 0 0 2 0 0-2 0 0 
}