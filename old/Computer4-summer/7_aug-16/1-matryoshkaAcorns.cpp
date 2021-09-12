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
const int MS = 1003;

int n, x, ans; v(int) a;
int main() {
    cin >> n;
    fo(i,n) { cin >> x; a.PB(x); } 

    while (a.size()) {
        sort(a.begin(), a.end());
        int prev = 0;
        fo(i,a.size()) {
            if (a[i] > prev) {
                prev = a[i];
                a.erase(a.begin()+i);
                i--;
            }
        }
        ans += prev;
    } 
    cout << ans << endl;
}