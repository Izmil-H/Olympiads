#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp; string name; int n;
int main(){
    cin >> n;
    for(int i=0; i<2*n-1; i++){
        cin >> name;  mp[name]++;
    }
    for(auto key: mp){
        if(key.second % 2 != 0) {
            cout << key.first << "\n"; break;
        }
    }
}