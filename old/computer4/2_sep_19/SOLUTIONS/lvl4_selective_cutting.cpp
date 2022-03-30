#include <bits/stdc++.h>
using namespace std;
const int MM = 100002;
struct Tree { int m, id; } t[MM];
struct Query { int l, r, v, id; } q[MM];
int N, Q, bit[MM], ans[MM];
bool cmp1(Tree x, Tree y){ return x.m > y.m; }
bool cmp2(Query x, Query y){ return x.v > y.v;}
void update(int pos, int val){
    for(pos++; pos<=N; pos+=pos&-pos)
        bit[pos] += val;
}
int query(int pos){
    int sol = 0;
    for(pos++; pos>0; pos-=pos&-pos)
        sol += bit[pos];
    return sol;
}
int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &t[i].m); t[i].id = i;
    }
    scanf("%d", &Q);
    for(int i=0; i<Q; i++){
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].v); q[i].id = i;
    }
    sort(t, t+N, cmp1); sort(q, q+Q, cmp2);
    for(int i=0, j=0; i<Q; i++){
        while(j < N && t[j].m >= q[i].v){
            update(t[j].id, t[j].m); j++;
        }
        ans[q[i].id] = query(q[i].r) - query(q[i].l-1);
    }
    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
}