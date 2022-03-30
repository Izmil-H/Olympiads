#include <bits/stdc++.h>
using namespace std;
int K, N, a[11][21], cnt;
int sgn(int x){ return x>0? 1:-1; }
int main(){
    cin >> K >> N;
    for(int i=1, x; i<=K; i++){
        for(int j=1; j<=N; j++){
            cin >> x; a[i][x] = j;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            int sign = sgn(a[1][i] - a[1][j]), flag = 1;
            for(int k=1; k<=K; k++)
                if(sgn(a[k][i] - a[k][j]) != sign) flag = 0;
            if(flag) cnt++;
        }
    }
    cout << cnt << "\n";
}