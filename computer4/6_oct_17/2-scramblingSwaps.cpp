#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mi map<int,int>
#define ml map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define pb push_back
#define f first
#define s second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, q, out[MS], pos[MS];
deque<pi> swaps;

int main() {
    cin >> n >> q;
    Fo(i,n) out[i] = pos[i] = i;
    
    char c; int x, y;
    fo(i,q) {
        cin >> c;
        if (c == 'B') {
            cin >> x >> y;
            swap(out[x], out[y]);
            swap(pos[out[x]], pos[out[y]]);
        } else if (c == 'E') {
            cin >> x >> y; 
            swap(out[pos[x]], out[pos[y]]);
            swap(pos[x], pos[y]);
        } else {
            int a[n+1];
            //cout << "-";Fo(j,n) cout << out[j] << " "; cout << endl;
            //cout << "_";Fo(j,n) cout << pos[j] << " "; cout << endl;
            Fo(j,n) cin >> a[j];
            Fo(j,n) cout << a[out[j]] << (j<n?' ':'\n');
        } 
    }
}
/*
4 5
B 3 4
B 2 3
q 1 2 3 4
E 1 2
Q 1 2 3 4
*/
