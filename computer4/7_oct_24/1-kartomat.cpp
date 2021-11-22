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

int n; string word;
bool ltr[26];

struct node {
    node *ch[26];
};

void insert(node *root, string &word) {
    node *cur = root;
    for (char c: word) {
        c -= 'A';
        if (cur->ch[c] == nullptr) {
            //cout << c+'a' << endl;
            cur->ch[c] = new node();
        }
        cur = cur->ch[c];
    }
}

void debug(node *root) {
    node *cur = root;
    fo(i,26) {
        if (cur->ch[i] != nullptr) {
            cout << char('A'+i);
            debug(cur->ch[i]);
        }
    }
}

void count(node *root, string &word) { 
    node *cur = root;
    for(char c: word) {
        cur = cur->ch[c-'A'];
    }   
    fo(i,26) {
        if (cur->ch[i] == nullptr) ltr[i] = 1;
    }
}

int main() {
    cin >> n;
    node *root = new node();
    fo(i,n) {
        cin >> word;
        insert(root, word);
    }
    cin >> word;
    count(root, word);
    fo(i,4) {
        fo(j,8) {
            int idx = i*8+j-3;
            cout << (idx<0||idx>=26||ltr[idx]? '*': char('A'+idx));
        }
        cout << "\n";
    }
}