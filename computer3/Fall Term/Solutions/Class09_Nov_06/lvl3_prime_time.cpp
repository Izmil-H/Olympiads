#include <bits/stdc++.h>
using namespace std;
int f[10002], n, m;
int main(){
    //freopen("test.txt", "r", stdin);
    for(int t=1; t<=5; t++){
        scanf("%d", &m); memset(f, 0, sizeof(f));
        for(int j=2; j<=m; j++){
            int n = j;
            for(int i=2, up=sqrt(n); i<=up; i++){
                while( n % i == 0 ){
                    f[i]++; n/=i;
                }
            }
            if(n != 1) f[n]++;
        }
        bool first = true;
        for(int i=2; i<=m; i++){
            if(f[i] != 0){
                if(!first) printf(" * %d^%d", i, f[i]);
                else { printf("%d^%d", i, f[i]); first = false;}
            }
        }
        printf("\n");
    }
}