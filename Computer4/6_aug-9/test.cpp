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

struct basic {
    int len = 5;
};

struct ptr {
    ptr *ch[26];
};

struct test {
    int n;
    v(test) *ch;
    map<int,test*> chM;
};

int main() {
    test *temp = new test();
    temp->chM[1] = new test();
    cout << temp->n << " " << temp->ch+1 << " " << temp->chM[1] << " ";
    if (temp->chM[0] == 0) cout << -1;
}