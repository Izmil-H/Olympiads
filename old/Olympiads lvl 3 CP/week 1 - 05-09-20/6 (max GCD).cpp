#include<iostream>
#include<bits/stdc++.h>
using namespace std; 
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a%b);
    }
}
int main(){
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> gcd;
    for (int i = 1; i < n+1; ++i) {
        int x = GCD(arr[i], arr[i-1]);
        if (i == n) {
            x = GCD(arr[0], arr[n-1]);
        }
        if (gcd.find(x) == gcd.end()) {
            gcd[x] = 1;
        } else {
            gcd[x]++;
        }
    }
    int big = 0;
    for (auto it : gcd) {
        cout << it.first << ":"<< it.second << endl;
        big = max(it.second, big);
    }
    for (auto it : gcd) {
        if (it.second == big) {
            cout << it.first;
        }
    }    
}
/*
    int gcd[2];
    gcd[0] = GCD(arr[0], arr[1]);
    int count[2] = {0,0};
    for (int i = 1; i < n; ++i) {
        int x = GCD(arr[i], arr[i-1]);
        if (i == 1) {
            x = GCD(arr[0], arr[n-1]);
        }
        if ( x != gcd[0]) {
            gcd[1] = x;
            ++count[1];
        } else {
            ++count[0];
        }
        cout << arr[i] << ":" << arr[i-1] << ":" << x << "|" << gcd[0] << "-" << count[0] << ":" << gcd[1] << "-" << count[1] << endl;
    }
    if (count[0] > count[1]) {
        cout << gcd[0];
    } else {
        cout << gcd[1];
    }
    */
    //absolutely wrong solution.