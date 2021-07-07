#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n]; 
    map<int,bool> mp;
    for (int i= 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]] = true;
    }
    int ans = 0;
    for (int i= 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (mp[arr[i]+arr[j]]) ans++;
        }
    }
    cout << ans;
}



/*
int main() {
    int n; cin >> n;
    int arr[n];
    for (int i= 0; i < n; i++) {
        cin >> arr[i];
    }
    map<int,set<pair<int,int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int a = arr[i], b = arr[j];
            mp[a+b].insert({min(a,b), max(a,b)});
        }
    }
    int sum = 0;
    for (auto s: mp) {
        sum += s.second.size();
        cout << s.first << ":\n  ";
        for (auto pr: s.second) {
            cout << pr.first << "," << pr.second << "  ";
        }
        cout << endl;
    }
    cout << sum;
}
*/