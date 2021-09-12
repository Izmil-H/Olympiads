#include <bits/stdc++.h>
using namespace std;
struct node {
    node * ch[2]; int idx;
    node(){ ch[0]=ch[1]=nullptr; idx=1e9;}
};
int N, Q, q, mask = 1<<30;  node *root;
void ins(node *cur, int x, int idx, int mask){
    if(!mask) { cur->idx = min(cur->idx, idx); return; }
    int bit = (x & mask) > 0;
    if(! cur->ch[bit] ) cur->ch[bit] = new node();
    ins(cur->ch[bit], x, idx, mask>>1);
}
int qry(node *cur, int x, int mask){
    if(! mask) return cur->idx;
    int bit = (x & mask) > 0;
    if(cur->ch[bit]) return qry(cur->ch[bit], x, mask>>1);
    return qry(cur->ch[!bit], x, mask>>1);
}
int main(){
    scanf("%d %d", &N, &Q); root = new node();
    for(int i=0, x; i<N; i++){
        scanf("%d", &x); ins(root, x, i, mask);
    }
    for(int i=0, x; i<Q; i++){
        scanf("%d", &x); q ^= x;
        printf("%d\n", qry(root, q, mask));
    }
}