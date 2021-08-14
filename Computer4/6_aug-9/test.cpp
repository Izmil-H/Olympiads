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

int main() {
    v(int) vec = {1,2,3,4,5};
    vec.erase(vec.begin() + 1);
    for (auto x: vec) cout << x << " ";
}