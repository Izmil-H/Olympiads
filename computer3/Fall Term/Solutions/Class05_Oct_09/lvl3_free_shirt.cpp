#include <bits/stdc++.h>
using namespace std;
int n, m, d, a[1002];
int main(){
    for(int t=1; t<=10; t++){
        cin >> n >> m >> d;
        memset(a, 0, sizeof(a));
        for(int i=0, x; i<m; i++){
            cin >> x; a[x]++;
        }
        int cnt = 0, num = n, used = 0;
        for(int i=1; i<=d; i++){
            if(used == num){
                cnt++; used = 0;
            }
            num += a[i]; used++;
        }
        cout << cnt << "\n";
    }
}