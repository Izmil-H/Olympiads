#include <bits/stdc++.h>
using namespace std;
int K, N, M, h[1000]; char g[1000][1000];
int getMaxRectInHist(int h[]){
    stack<int> stk; int area = 0;
    for(int i=0; i<M; i++){
        while(!stk.empty() && h[stk.top()] >= h[i]){
            int idx = stk.top(); stk.pop();
            int lft = stk.empty()? -1 : stk.top(), rit = i;
            area = max(area, (rit-lft-1)*h[idx]);
        }
        stk.push(i);
    }
    while(!stk.empty()){
        int idx = stk.top(); stk.pop();
        int lft = stk.empty()? -1 : stk.top(), rit = M;
        area = max(area, (rit-lft-1)*h[idx]);
    }
    return area;
}
int main(){
   for(scanf("%d", &K); K > 0; K--) {
        scanf("%d %d", &N, &M);  int ans = 0;
        memset(h, 0, sizeof(h));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                scanf(" %c", &g[i][j]);
                if(g[i][j] == 'F') h[j]++;
                else h[j] = 0;
            }
            ans = max(ans, getMaxRectInHist(h));
        }
        printf("%d\n", ans*3);
   }
}