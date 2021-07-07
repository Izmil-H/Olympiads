#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[8];
    for(int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    bool asc = false, desc = false;
    for (int i = 1; i < 8; ++i) {
        if (arr[i] > arr[i-1]) asc = true;
        else desc = true;
    }
    if (asc && desc) cout << "mixed";
    else if(asc) cout << "ascending";
    else if (desc) cout << "descending"; 
}