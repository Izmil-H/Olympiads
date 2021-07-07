#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int big = INT_MIN;
    long int sum  = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        big = max(big, arr[i]);
    }
    if (big >= sum-big) {
        cout << sum-big;
    } else {
        cout << sum/2 <<endl;
    }
}


/*
int main(){
    long int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        long int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long int sum = 0;

    while(arr.size() > 1) {
        sum += arr.front();
        arr.back() -= arr.front();
        arr.erase(arr.begin()); 
        sort(arr.begin(), arr.end());
    }
    cout << sum;
}
*/