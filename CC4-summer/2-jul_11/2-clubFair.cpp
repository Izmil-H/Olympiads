#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}


int main() {
    int n, q, x, y, r;
    vector<int> key, val;
    stack<int> stk;

    cin >> n >> q;
    fo(i,n) {
        cin >> x >> y; 
        int shft = 0;
        int dst = ceil(sqrt(x*x + y*y));
        if (!stk.size()) stk.push(dst);
        else {
            while (dst < stk.top()) {
                shft++; stk.pop();
                if (!stk.size()) break;
            }
            stk.push(dst);
        }
        key.insert(key.end()-shft, dst);
        val.insert(val.end()-shft, stk.size());
    }

    fo(i,q) {
        cin >> r;
        int ind = lower_bound(key.begin(), key.end(), r) - key.begin();
        cout << (key[ind] == r? val[ind]: val[ind-1]) << endl;
        cout << endl;
    }
    //for(auto it: key) cout << it << " "; cout << endl;
    //for(auto it: val) cout << it << " ";