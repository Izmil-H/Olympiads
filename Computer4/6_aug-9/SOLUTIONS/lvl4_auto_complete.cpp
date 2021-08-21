#include <bits/stdc++.h>
using namespace std;

struct node { 
    node *ch[26]; 
};

int T, n, ans; string word;

void insert(node *root, string& word){
    node *cur = root; int pre = 0, flag = 1;
    for(char c: word){
        c -= 'a';
        if(flag) pre++;
        if(cur->ch[c] == nullptr){
            cur->ch[c] = new node();
            flag = 0;
        }
        cur = cur->ch[c];
    }
    ans += pre;
}

void remove(node *root){
    if(!root) return;
    for(auto e: root->ch) remove(e);
    delete root; root=nullptr;
}

int main(){
    //freopen("test.txt", "r", stdin);
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        cin >> n; ans = 0;
        node * root = new node();
        for(int i=0; i<n; i++){
            cin >> word; insert(root, word);
        }
        cout << ans << endl;
        remove(root);
    }
}