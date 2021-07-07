#include<bits/stdc++.h>
using namespace std;

bool sorter(pair<string,int> a, pair<string,int> b) {
    return a.second > b.second;
}

int main() {
    int n, p;
    cin >> n >> p;
    pair<string, int> arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = 0;
    }
    for (int i= 0; i < p; i++) {
        for (int j = 0, x; j < n; j++) {
            cin >> x;
            arr[j].second += x;
        }
    }
    sort(arr, arr+n, sorter); 
    for (int i = 0; i < n; i++) {
        cout << i+3 << ". " << arr[i].first << endl;
    }
}