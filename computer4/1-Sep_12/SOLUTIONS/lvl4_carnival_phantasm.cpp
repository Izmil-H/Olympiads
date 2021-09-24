#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 1e5+2;
int N, S, Q, dis[MM]; set<pi> candy[102]; char op;
int main(){
    scanf("%d %d", &N, &S);
    for(int i=1; i<=N; i++) scanf("%d", &dis[i]);
    for(int i=1, x, y; i<=S; i++){
        scanf("%d %d", &x, &y); candy[y].insert({dis[x], x});
    }
    scanf("%d", &Q);
    for(int i=1, x, k; i<=Q; i++){
        scanf(" %c %d", &op, &x);
        if(op == 'A'){
            scanf("%d", &k); candy[k].insert({dis[x], x});
        }else if(op == 'S'){
            scanf("%d", &k); candy[k].erase({dis[x], x});
        }else if(op == 'E'){
            scanf("%d", &k);
            for(int j=1; j<=100; j++) candy[j].erase({dis[x], x});
            dis[x] = k;
        }else{
            if(candy[x].empty()) printf("-1\n");
            else printf("%d\n", candy[x].begin()->second);
        }
    }
}