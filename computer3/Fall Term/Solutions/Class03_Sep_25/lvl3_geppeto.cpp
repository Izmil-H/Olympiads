#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, mask[22];
int main(){
    scanf("%d %d", &N, &M);
    for(int i=1, x, y; i<=M; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        mask[x] = mask[x] | (1<<y);
    }
    for(int i=0, t=(1<<N); i<t; i++){
        bool flag = true;
        for(int j=0; j<N; j++){
            if((i>>j & 1) && (i & mask[j])) { flag=false; break;}
        }
        if(flag) cnt++;
    }
    printf("%d\n", cnt);
}