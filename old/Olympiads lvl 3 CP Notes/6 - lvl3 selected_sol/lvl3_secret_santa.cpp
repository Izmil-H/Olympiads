#include <bits/stdc++.h>
using namespace std;
int N, totW, f[8], w[8], id[8], ans=1e9;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> f[i] >> w[i];
        id[i] = i; totW += w[i];
    }
    do{
        int cur = 101, stress = totW, tmp = 0;
        for(int i=0; i<N; i++){
            int k = id[i];
            tmp += (abs(cur - f[k]) + 1)*stress;
            cur = f[k]; stress -= w[k];
        }
        ans = min(ans, tmp);
    }while(next_permutation(id, id+N));
    cout << ans << endl;
}