#include <stdio.h>
int adj[4][4], vis[4], i, j, cnt;
int main(){
    for(i=0; i<4; i++)
        for(j=0; j<4; j++){
            scanf("%d", &adj[i][j]);
            cnt += adj[i][j];
        }
    if(cnt!=6) {printf("No\n"); return 0;}
    for(i=0; i<4; i++){
        cnt = 0;
        for(j=0; j<4; j++){
            cnt += adj[i][j];
        }
        if(!cnt) {printf("No\n"); return 0;}
    }
    printf("Yes\n"); return 0;
}