#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string one[n], two[n]; map<string,int> mTwo;
    for (int i = 0; i < n; i++) cin >> one[i];
    for (int i = 0; i < n; i++) { cin >> two[i]; mTwo[two[i]] = i;}
    
    bool ans = true;
    for(int i= 0; i < n; i++) {
        if (two[i] != one[mTwo[one[i]]] || one[i] == two[i]) {
            ans = false;
            break;
        }
    }
    
    if (ans) cout << "good";
    else cout << "bad";
}