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
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, x, y; pii p[MS]; ll area = 0, mod = 1e9+7;

void fun() {
    sort(p, p+n);
    int mv = 1e4+2;
    int cx[2*mv], cy[2*mv], lx[2*mv], ly[2*mv];
    ll sx[2*mv], sy[2*mv]; 
    fo(i,n) {
        int x = p[i].F + mv, y = p[i].S + mv;
        sx[x] = (sx[x] + cx[x]*(y - lx[x]))%mod;
        sy[y] = (sy[y] + cy[y]*(x - ly[y]))%mod;
        cx[x]++; cy[y]++; lx[x] = y; ly[y] = x;
        area = (area + sx[x]*sy[y]%mod)%mod;
    }
}
void rot() {
    fo(i,n) {
        int x = p[i].F, y = p[i].S;
        p[i].F = -y, p[i].S = x;
    }
}

int main() {
    cin >> n;
    fo(i,n) {
        cin >> x >> y;
        p[i] = {x,y};
    }
    fo(i,4) {
        fun(); rot();
    }
    cout << area;
}