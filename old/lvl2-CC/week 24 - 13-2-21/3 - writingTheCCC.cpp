#include<bits/stdc++.h>
using namespace std;

bool sorter(pair<int,int> a, pair<int,int> b){ 
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int t; cin >> t;
    map<string,int> types;
    for (int i = 0; i < t; i++) {
        string s; cin >> s;
        types[s] = i;
    }
    
    int n; cin >> n;
    pair<int,int> arr[n];
    for (int i= 0; i <n; i++) {
        string s; cin >> s;
        arr[i].first = types[s];
        arr[i].second = i;
    }
    sort(arr,arr+n, sorter);
    for (auto i: arr) {
        cout << i.second + 1 << endl;
    }
}