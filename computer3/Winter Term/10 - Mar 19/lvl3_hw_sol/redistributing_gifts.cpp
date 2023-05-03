#include <bits/stdc++.h>
using namespace std;
const int MM = 502;
int N, a[MM][MM]; bool adj[MM][MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cin >> a[i][j];
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){
            adj[i][a[i][j]] = true;
            if(a[i][j] == i) break;
        }
    }
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(adj[i][k] && adj[k][j]) adj[i][j]=true;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][a[i][j]] && adj[a[i][j]][i]){
                cout << a[i][j] << "\n"; break;
            }
        }
    }
}