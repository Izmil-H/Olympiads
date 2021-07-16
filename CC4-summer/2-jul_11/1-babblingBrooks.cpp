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
    int n, x, a, b; 
    vector<int> strms;
    cin >> n;
    fo(i,n) {
        cin >> x;
        strms.PB(x);
    } 
    
    while (true) {
        //for(auto it: strms) cout << it << " "; cout << endl;
        cin >> x;
        if (x == 99) {
            cin >> a >> b;
            int val = strms[a-1] * b/100.0;
            strms.insert(strms.begin() + a, strms[a-1]-val);
            strms[a-1] = val;
        } else if (x == 88) {
            cin >> a;
            strms[a-1] += strms[a];
            strms.erase(strms.begin() + a);
        } else {
            break;
        }
    }
    for(auto it: strms) cout << it << " ";
}