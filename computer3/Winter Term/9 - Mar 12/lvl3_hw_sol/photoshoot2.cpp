#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, a[MM], b[MM], ans; bool used[MM];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> a[i];
    for(int i=1; i<=N; i++) cin >> b[i];
    for(int i=1, j=1; j<=N; j++) {
        while(i <= N && used[a[i]]) i++;
        if(a[i] == b[j]) i++;
        else { ans++; used[b[j]] = 1;}
    }
    cout << ans << endl;
}