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

struct node {
    node *ch[26];
};

int T, n, ans; string word;

void insert(node *root, string &word) {
    node *cur = root; int pre = 0, seen = 1;
    for(char c: word) {
        c -= 'a';
        if(seen) pre++;
        if (cur->ch[c] == nullptr) {
            cur->ch[c] = new node();
            seen = 0;
        }
        cur = cur->ch[c];
    }
    ans += pre;
}

void remove(node *par) {
    if (!par) return;
    for (auto e: par->ch) remove(e);
    delete par; par = nullptr;
}

int main() {
    cin >> T;
    fo(t,T) {
        cin >> n; ans = 0;
        node *root = new node();
        fo(i,n) {
            cin >> word;
            insert(root, word);
        }
        cout << "Case #" << t+1 << ": " << ans << endl;
        remove(root);
    }
}