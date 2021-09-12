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


bool a[10002][10002];

int main() {
    int n, m, x, y, w, h;
    cin >> n >> m;

    fo(i,m) {
        cin >> x >> y >> w >> h;
        x++;y++;
        a[x][y] ^= 1; 
        a[x+w][y] ^= 1;
        a[x][y+h] ^= 1;
        a[x+w][y+h] ^= 1;
    } 


    Fo(i,1,n+2,1) {
        Fo(j,1,n+2,1) {
            a[i][j] ^= a[i][j-1];
        }
    }

    int ans = 0;
    Fo(i,1,n+2,1) {
        Fo(j,1,n+2,1) {
            a[j][i] ^= a[j-1][i];
            if (a[j][i]) ans++;
        }
    }

    cout << ans;
}