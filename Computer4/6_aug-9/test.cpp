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
const int MS = 5e5+2;

int n, m, r[MS], c[MS], ans;
char s[2][10];

int main() {
    cin >> s[0];
    fo(i,2) {
        fo(j,10) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}