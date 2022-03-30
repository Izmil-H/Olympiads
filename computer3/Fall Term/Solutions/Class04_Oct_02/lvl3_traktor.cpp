#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+3;
int N, K, row[MM], col[MM], lft[2*MM], rit[2*MM];
int main(){
    scanf("%d %d", &N, &K);
    for(int i=1, r, c; i<=N; i++){
        scanf("%d %d", &r, &c);
        row[r]++; col[c]++; lft[r+c]++; rit[r+N-c]++;
        if(row[r]>=K || col[c]>=K || lft[r+c]>=K || rit[r+N-c]>=K){ printf("%d\n", i); return 0; }
    }
    printf("-1\n");
}