#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; string s;
    cin >> n >> s;
    for(int len=1; len<=n; len++){
        bool flag = true;
        for(int i=0; i+len<=n; i++){
            string sub = s.substr(i, len);
            int p1 = s.find(sub);
            int p2 = s.find(sub, p1+1);
            if(p2 != -1) { flag = false; break; }
        }
        if(flag) { cout << len << endl; return 0; }
    }
}