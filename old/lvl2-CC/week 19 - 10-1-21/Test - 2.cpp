#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, y; cin >> n >> y;
    string names[n];
    map<string,int> dict;
    for (int i = 0; i < n; i++) {
        cin >> names[n];
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        dict[names[i]] = a;
    }
    
    int sum = 0;
    for (int i = 0; i < y; i++) {
        string s; cin >> s;
        sum += dict[s];
        dict[s] = 0;
    }
    cout << sum;
}