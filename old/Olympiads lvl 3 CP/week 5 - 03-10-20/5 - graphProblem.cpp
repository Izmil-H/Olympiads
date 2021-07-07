#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sum = 0; 
    int large = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        if (x > large) large = x;
        sum += x;
    }
    if ((sum % 2 == 0) && (large <= sum-large)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}