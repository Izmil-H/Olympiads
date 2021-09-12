#include <bits/stdc++.h>
using namespace std;
struct Node{
    int mx; unordered_map<int, Node*> nxt;
};
string s; int n, mod = 1e9+7;
void insert_node(Node * root, string &s, int idx){
    if(idx == s.size()) return;
    if(s[idx] == '.') idx++;
    int val = 0;
    while(idx<s.size() && isdigit(s[idx])) { val = val*10 + s[idx]-'0'; idx++;}
    root->mx = max(root->mx, val);
    if(!root->nxt.count(val)) root->nxt[val] = new Node();
    insert_node(root->nxt[val], s, idx);
}
long long cnt(Node *root){
    if(root == NULL) return 0;
    long long ret = root->mx;
    for(auto it: root->nxt) { ret += cnt(it.second); ret %= mod; }
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int t=1; t<=10; t++){
        cin >> n; Node *root = new Node();
        for(int i=1; i<=n; i++){
            cin >> s; insert_node(root, s, 0);
        }
        cout << 1 + cnt(root) << "\n";
    }
}