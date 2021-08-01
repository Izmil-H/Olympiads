#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INTM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}

deque<int> in1, in2, nw;

bool solve(deque<int> og) {
    nw.clear();
    nw.PB(og.back()); og.pop_back();
    while (true) {
        if (nw.front()-1 == og.front()) {
            nw.push_front(og.front()); og.pop_front();
        } else if (nw.front()-1 == og.back()) {
            nw.push_front(og.back()); og.pop_back();
        } else if (nw.back()+1 == og.front()) {
            nw.push_back(og.front()); og.pop_front();
        } else if (nw.back()+1 == og.back()) {
            nw.push_back(og.back()); og.pop_back();
        } else {
            if (og.size()) return false; 
            break;
        }
    }
    return true;
}

int main() {
    int t, n, x; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n; 
        in1.clear(); in2.clear(); 
        fo(i,n) { 
            cin >> x; 
            in1.push_front(x);
            in2.push_back(x);  
        }
        bool ans = 0;
        ans += solve(in1);
        ans += solve(in2);
        cout << "Case #" << tc << ": " << (ans? "yes": "no") << endl;
    }
}