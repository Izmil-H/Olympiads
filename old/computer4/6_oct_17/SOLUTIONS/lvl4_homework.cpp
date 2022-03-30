#include <bits/stdc++.h>
using namespace std;
int N; vector<double> pt[1000001]; double v;
int main(){
    for(int t=1; t<=10; t++){
        scanf("%d", &N);
        for(int i=0; i<=1e6; i++) pt[i].clear();
        double ans = 0.0; int mx = 0;
        for(int i=1, d; i<=N; i++){
            scanf("%d %lf", &d, &v); pt[d].push_back(v);
            mx = max(mx, d);
        }
        priority_queue<double> q;
        for(int i=mx; i>=1; i--){
            for(double v: pt[i]) q.push(v);
            if(!q.empty()){
                ans += q.top(); q.pop();
            }
        }
        printf("%.4f\n", ans);
    }
}