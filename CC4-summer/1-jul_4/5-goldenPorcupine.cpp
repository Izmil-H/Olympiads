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


const int sz = 1e5;
ll ar[sz];
int A[sz], B[sz], C[sz];
int main() {
    int n, t;
    cin >> n >> t;
    
    fo(i,n) {
        int L, R, a, b, c;
        cin >> L >> R >> a >> b >> c;
        
        fo(j,R-L+1) ar[L+j] += a*(j*j) + b*j + c;
    }
    
    Fo(i,1,t+1,1) cout << ar[i] << " ";
}


