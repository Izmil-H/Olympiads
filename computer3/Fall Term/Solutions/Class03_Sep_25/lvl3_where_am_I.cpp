#include <bits/stdc++.h>
using namespace std;
int N; string s;
int main(){
    cin >> N >> s;
    for(int len = 1; len <= N; len++){
        unordered_set<string> used;
        bool flag = true;
        for(int i=0; i+len <= N; i++) {
            string sub = s.substr(i, len);
            if(used.count(sub)) {
                flag = false; break;
            }
            used.insert(sub);
        }
        if(flag) {
            cout << len << endl;
            return 0;
        }
    }
}