#include <bits/stdc++.h>
using namespace std;
int N, M, p[100002]; vector<int> edge;
int fd(int d){
    if(d != p[d]) p[d] = fd(p[d]);
    return p[d];
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) p[i] = i;
    for(int i=1, u, v; i<=M; i++){
        scanf("%d %d", &u, &v);
        int fu = fd(u), fv = fd(v);
        if(fu != fv){ p[fu] = fv; edge.push_back(i); }
        if(edge.size()==N-1) break;
    }
    if(edge.size() != N-1) printf("Disconnected Graph\n");
    else{
        for(int x: edge) printf("%d\n", x);
    }
}