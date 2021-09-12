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
const int mod = 1e9+7;


struct node {
    int n = 0;
    map<int, node*> ch;
};

v(int) getID(string s) {
    v(int) id;
    while (s.size()) {
        int idx = s.find('.');
        if (idx < 0) idx = s.size();
        id.PB(stoi(s.substr(0,idx)));
        s.erase(0,idx+1);
    }
    return id;
}

void insert(node *root, v(int) id) {
    node *cur = root; int gen = 0;
    for(int dig: id) {
        cur->n = max(cur->n, dig);
        if (dig == 0) continue;
        if (cur->ch[dig] == nullptr) {
            cur->ch[dig] = new node();
        }
        cur = cur->ch[dig];
    }
}

void clear(node* root) {
    if (!root) return;
    for (auto e: root->ch) clear(e.S);
    delete root; root = nullptr;
}

ll getSize(node* root) {
    ll size = root->n;
    for(auto e: root->ch) {
        size += getSize(e.S);
    }
    return size % mod;
}

int main() {
    fo(t,10) {
        int n; string s;
        cin >> n; cin.ignore();
        node *zero = new node();
        fo(i,n) {
            getline(cin, s);
            insert(zero, getID(s)); 
        }
        cout << (getSize(zero) + 1) % mod << endl;
        clear(zero);
    }
}