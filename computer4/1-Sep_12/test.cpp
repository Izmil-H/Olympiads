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
ll qAt(ll tree[MS], int idx) {
    ll sum = tree[idx];
    if (idx) {
        int z = idx - (idx & -idx), y = idx -1;
        //cout << z << ": ";
        while (y > z) {
            cout << sum << " ";
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
        bit[i] += a;
        int pa = i + (i&-i); 
        if(pa <= n) bit[pa] += bit[i];
        bitF[a]++; bitF[a + (a & -a)]++;
    } cout << endl;
    fo(i,n+1) cout << bit[i] << " "; cout << endl;
    fo(i,n+1) cout << bitF[i] << " "; cout << endl;

    //fo(i,n+1) cout << qAt(bit, i) << " "; cout << endl;
    //fo(i,n+1) cout << qTo(bit, a) << " "; cout << endl;
    //int x = qAt(bit,4);
}