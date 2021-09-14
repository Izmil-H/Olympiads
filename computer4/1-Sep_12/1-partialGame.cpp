#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define v(t) vector<t>
#define pii pair<int,int>
#define mii map<int,int>
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}

int main() {
    int n, x, d = 0, a = 0;
    cin >> n;
    fo(i,n) {
        cin >> x;
        if (x%2) a += ceil(x/2.0);
        else d += ceil(x/2.0);
    }
    cout << (d <= a? "Alice": "Duke") << endl;
}