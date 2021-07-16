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


const int sz = 1e5 + 3;
ll d1[sz], d2[sz], d3[sz];
int main() {
    int n, t;
    cin >> n >> t;
    
    fo(i,n) {
        int L, R, a, b, c;
        cin >> L >> R >> a >> b >> c;
        d1[L] += a; d1[R+1] -= a;
        ll temp = b-2*a*L;
        d2[L] += temp; d2[R+1] -= temp;
        temp = a*L*L - b*L + c;
        d3[L] += temp; d3[R+1] -= temp;       
    }
    
    Fo(i,1,t+1,1) {
        d1[i] += d1[i-1];
        d2[i] += d2[i-1];
        d3[i] += d3[i-1];
        cout << d1[i]*i*i + d2[i]*i + d3[i] << " ";
    }
}


