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
ll bit[MS], bitF[MS], freq[MS];

void update(ll tree[MS], int idx, int x, int lim) {
    while (idx <= lim) {
        tree[idx] = x;
        idx += (idx & -idx);
    }
}
ll qTo(ll tree[MS], int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
ll qAt(ll tree[MS], int idx) {
    ll sum = tree[idx];
    if (idx) {
        int z = idx - (idx & -idx), y = idx -1;
        while (y > z) {
            sum -= tree[y];
            y -= (y & -y);
        }
    }
    return sum;
}

int main() {
    cin >> n;
    Fo(i,1,n+1,1) {
        cin >> a;
        bit[i] += a; bit[i + (i & -i)] += bit[i];
        freq[a]++;
    }
    Fo(i,1,n+1,1) {
        bitF[i] += freq[i]; bitF[i + (i & -i)] += bitF[i];
    }
    fo(i,n+1) cout << bit[i] << " "; cout << endl;
    fo(i,n+1) cout << bitF[i] << " "; cout << "\n\n";

    fo(i,n+1) cout << qAt(bit, i) << " "; cout << endl;
    fo(i,n+1) cout << qAt(bitF, i) << " "; cout << endl;
    //int x = qAt(bit,4);
}