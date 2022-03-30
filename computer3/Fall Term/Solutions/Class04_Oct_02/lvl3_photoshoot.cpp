#include <bits/stdc++.h>
using namespace std;
int N, b[1002], a[1002]; bool vis[1002];
int main(){
    scanf("%d", &N);
    for(int i=1; i<N; i++) scanf("%d", &b[i]);
    for(int i=1; i<=N; i++){
        memset(vis, 0, sizeof(vis)); bool flag = true;
        a[i] = 1; vis[1] = true;
        for(int j=i-1; j>0 && flag; j--){
            a[j] = b[j] - a[j+1];
            if(a[j] < 1 || a[j] > N || vis[a[j]] ){
                flag = false; break;
            }
            vis[a[j]] = true;
        }
        for(int j=i+1; j<=N && flag; j++){
            a[j] = b[j-1] - a[j-1];
            if(a[j] < 1 || a[j] > N || vis[a[j]] ){
                flag = false; break;
            }
            vis[a[j]] = true;
        }
        if(flag){
            for(int i=1; i<=N; i++) printf("%d ", a[i]);
            break;
        }
    }
}