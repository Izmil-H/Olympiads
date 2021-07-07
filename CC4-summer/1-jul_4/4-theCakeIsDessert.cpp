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


int a[5002][5002];
int main() {
    int n, m, k, q, x1, y1, x2, y2;
    cin >> n >> m >> k;

    int pS = 1;
    int pE = 1;

    fo(i,k) {
        cin >> x1 >> y1 >> x2 >> y2;
        a[y1][x1]++;
        a[y2+1][x1]--;
        a[y1][x2+1]--;
        a[y2+1][x2+1]++;
        //Fo(i,pS,m+pE,1) { Fo(j,pS,n+pE,1) { cout << setw(2) << setfill(' ') << a[i][j]; } cout << endl;}cout <<endl;
    }
    
    
    Fo(i,1,m+1,1) {
        Fo(j,1,n+1,1) {
            a[i][j] += a[i][j-1];
        }
    }
    Fo(i,1,n+1,1) {
        Fo(j,1,m+1,1) {
            a[j][i] += a[j-1][i];
        }
    }
    
    Fo(i,1,m+1,1) {
        Fo(j,1,n+1,1) {
            a[i][j] += a[i][j-1];
        }
    }
    Fo(i,1,n+1,1) {
        Fo(j,1,m+1,1) {
            a[j][i] += a[j-1][i];
        }
    }
    //Fo(i,pS,m+pE,1) { Fo(j,pS,n+pE,1) { cout << setw(3) << setfill(' ') << a[i][j]; } cout << endl;} cout << endl;

    cin >> q;
    fo(i,q) {
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = a[y2][x2] - a[y1-1][x2] - a[y2][x1-1] + a[y1-1][x1-1];
        cout << ans << endl;
        //cout << "-- " << a[y2][x2] << " " << a[y1-1][x2] << " " << a[y2][x1-1] << " " << a[y1-1][x1-1] << endl;
    }
}

/*
1 1 1 1 1 1
0 1 1 0 0 0
1 2 2 1 0 0 
1 1 1 1 0 0
1 1 1 1 0 0


1 1 1 1 0 0
1 1 1 1 0 0
1 2 2 1 0 0
0 1 1 0 0 0
1 1 1 1 1 1
*/