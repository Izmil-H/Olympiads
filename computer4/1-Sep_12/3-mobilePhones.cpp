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
const int MS = 1024+2;

int op, N, bit[MS][MS];

void update(int x, int y, int val) {
    for (int r = x; r < MS; r += (r & -r)) {
        for (int c = y; c < MS; c += (c & -c)) {
            bit[r][c] += val;
        }
    }
}
int sum(int x, int y) {
    int tot = 0;
    for (int r = x; r > 0; r -= (r & -r)) {
        for (int c = y; c > 0; c -= (c & -c)) {
            tot += bit[r][c];
        }
    }
    return tot;
}

int main() {
    cin >> op >> N;
    while (true) {
        cin >> op;
        if (op == 3) break;
        if (op == 1) {
            int x, y, a; 
            cin >> x >> y >> a; x++, y++;
            update(x, y, a);  
        } else {
            int l, b, r, t;
            cin >> l >> b >> r >> t; r++; t++;
            cout << sum(r,t) - sum(l, t) - sum(r, b) + sum(l,b) << endl;
        }
    }
}