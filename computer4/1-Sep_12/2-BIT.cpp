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
const int MS = 1e5+2;

int n, m, a; 
ll bit[MS], bitF[MS];

void update(ll tree[MS], int i, int x) {
    while (i <= n) {
        tree[i] = x;
        i += (i & -i);
    }
}
ll qTo(ll tree[MS], int i) {
    ll sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= (i & -i);
    }
    return sum;
}
ll qAt(ll tree[MS], int i) {
    ll sum = tree[i];
    if (i) {
        int z = i - (i & -i), y = i -1;
        while (y != z) {
            sum -= tree[y];
            y -= (y & -y);
        }
    }
}


int main() {
    cin >> n >> m;
    Fo(i,1,n+1,1) {
        cin >> a;
        bit[i] = bit[i & -i] = a;
        bitF[a]++; bitF[a & -a]++;
    }

    char c; int x, y;
    fo(i,m) {
        cin >> c >> x;
        if (c == 'Q') {
            cout << qTo(bitF, x) << endl;
        } else if (c == 'C') {
            cin >> y;
            int v = qAt(bit, x), f = qAt(bitF, v)-1, f2 = qAt(bitF, y);
            update(bit, x, y);
            update(bitF, v, f); update(bitF, y, f2+1);
        } else {
            cin >> y; 
            cout << qTo(bit, x) - qTo(bit, x-1) << endl;
        }
    }
}