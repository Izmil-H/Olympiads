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

int t;
ll a, b;

int main() { 
    for(cin >> t; t--;) {
        cin >> a >> b;
        int t = 0, f = 0;

        b /= __gcd(a,b);
       
        while (b%2 == 0) { b /= 2; t++; }
        while (b%5 == 0) { b /= 5; f++; }
        
        cout << (b > 1? -1: max(t,f)) << endl;
    }
}
