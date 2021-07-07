#include<bits/stdc++.h>
using namespace std; 

int main() {
    int n; cin >> n;
    int arr[n+1] = {0}; arr[n] = 1000000001;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count = 0, longest = 0;
    for (int i = 0; i < n; i++) {
        if(arr[i] >= arr[i+1]) count++;
        else {
            longest = max(longest, count+1);
            count = 0;
        }        
    }
    cout << longest;
}
