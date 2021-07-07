#include<bits/stdc++.h>
using namespace std;


bool sortByUnit(int a, int b) {
    if (a%10 != b%10) {
        return a%10 < b%10;
    }
    return a > b;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n, sortByUnit);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
} 
