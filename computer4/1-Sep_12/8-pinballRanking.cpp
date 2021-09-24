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

int n, rk, a[MS], bit[MS];
map<int,int> mp; ll ans;

void update(int idx, int val) {
    for (int i = idx; i < MS; i += (i & -i)) {
        bit[i] += val;
    }
}
int query(int idx) {
    int sum = 0;
    for(int i = idx; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}

int main() {
    cin >> n;
    Fo(i,1,n+1,1) {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    for(auto &x: mp) x.S = ++rk;
    Fo(i,1,n+1,1) {
        int x = mp[a[i]];
        ans += i - query(x);
        update(x,1);
    }
    cout << fixed << setprecision(2) << (double)ans/n << endl;
}