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

int n, m, a[MS]; 
ll bit[MS], bitF[MS];

void update(ll tree[], int idx, int val) {
    for(int i = idx; i < MS; i += (i & -i)) {
        tree[i] += val;
    }
}
ll query(ll tree[], int idx) {
    ll sum = 0;
    for(int i = idx; i > 0; i -= (i & -i)) sum += tree[i];
    return sum;
}

int main() {
    cin >> n >> m;
    Fo(i,1,n+1,1) {
        cin >> a[i];
        update(bit, i, a[i]);
        update(bitF, a[i], 1);
    }

    fo(i,m) {
        char op; int x, y;
        cin >> op >> x;
        if (op == 'Q') {
            cout << query(bitF, x) << endl;
        } else if (op == 'C') {
            cin >> y;
            update(bit, x, y-a[x]);
            update(bitF, a[x], -1);
            update(bitF, y, 1);
            a[x] = y;
        } else {
            cin >> y;
            cout << query(bit, y) - query(bit, x-1) << endl;
        }
    }
}