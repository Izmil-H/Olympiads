#include <bits/stdc++.h>
using namespace std;
int T, N, K;
int main(){
    for(cin >> T; T--; ){
        cin >> N >> K;
        int sum = 0, cnt = 0;
        for(int i=1, x; i<=N; i++){
            cin >> x;
            sum += x;
            if(sum >= K) { sum = 0; cnt++; }
        }
        cout << cnt << "\n";
    }
}