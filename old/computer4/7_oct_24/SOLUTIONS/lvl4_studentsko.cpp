#include <bits/stdc++.h>
using namespace std;
const int MM = 5002;
typedef pair<int, int> pi;
int N, K, gp[MM]; pi f[MM]; vector<int> lis;
int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", &f[i].first); f[i].second = i;
    }
    sort(f, f+N);
    for(int i=0; i<N; i++)
        gp[f[i].second] = i / K;
    for(int i=0; i<N; i++){
        if(lis.empty() || gp[i] >= lis.back()) lis.push_back(gp[i]);
        else *(upper_bound(lis.begin(), lis.end(), gp[i])) = gp[i];
    }
    printf("%d\n", N - lis.size());
}