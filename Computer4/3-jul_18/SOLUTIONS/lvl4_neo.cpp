#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
int R, C, a[MM][MM], h[MM], ans; stack<int> st;
int solve(){
   int idx = 1, ret = 0, area = 0;
   while(idx < C){
        if(st.empty() || h[st.top()] < h[idx]) st.push(idx++);
        else {
            int t = st.top(); st.pop();
            if(st.empty()) area = (h[t]+1)*idx;
            else area = (h[t]+1)*(idx - st.top());
            ret = max(ret, area);
        }
   }
   while(!st.empty()){
        int t= st.top(); st.pop();
        if(st.empty()) area = (h[t]+1)*C;
        else area = (h[t]+1)*(C - st.top());
        ret = max(ret, area);
   }
   return ret;
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d", &R, &C);
    for(int j=1; j<=C; j++) scanf("%d", &a[1][j]);
    for(int i=2; i<=R; i++){
        scanf("%d", &a[i][1]);
        for(int j=2; j<=C; j++){
            scanf("%d", &a[i][j]);
            if(a[i-1][j-1] + a[i][j] <= a[i-1][j] + a[i][j-1]) a[i-1][j-1]=1;
            else a[i-1][j-1] = 0;
        }
    }
    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            if(a[i][j]) h[j]++;
            else h[j] = 0;
        }
        ans = max(ans, solve());
    }
    printf("%d", ans);
}