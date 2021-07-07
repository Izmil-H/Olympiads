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


const int sz = 1e4;
short a[sz+2][sz+2];

int main() {
    int n, m, x, y, w, h;
    cin >> n >> m;

    fo(i,m) {
        cin >> x >> y >> w >> h;
    } 

    //Fo(i,0,n+2,1) { Fo(j,0,n+2,1) { cout << setw(2) << setfill(' ') << a[i][j]; } cout << endl;}

    Fo(i,1,n+2,1) {
        Fo(j,1,n+2,1) {
            a[i][j] += a[i][j-1];
        }
    }
    int ans = 0;
    Fo(i,1,n+2,1) {
        Fo(j,1,n+2,1) {
            a[j][i] += a[j-1][i];
            if (a[j][i]%2) ans++;
        }
    }

    //cout << endl; Fo(i,0,n+2,1) { Fo(j,0,n+2,1) { cout << setw(2) << setfill(' ') << a[i][j]; } cout << endl;}
    cout << ans;
}