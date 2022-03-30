#include <bits/stdc++.h>
using namespace std;
const int MM = 1.5e5 + 10, LOG=18;
int N, M, dif[17][MM], st[LOG][MM], x[MM], y[MM], z[MM];
int lcm(int x, int y) { return x/__gcd(x, y)* y;}
int gcdQuery(int x, int y) {
    int k = log2(y - x + 1);
    return __gcd(st[k][x], st[k][y-(1<<k)+1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;

    //input and difference array for each z 
    for(int i=1; i<=M; i++) {
        cin >> x[i] >> y[i] >> z[i];
        dif[z[i]][x[i]]++; dif[z[i]][y[i]+1]--;
    }

    // build difference arrays
    // for each index, find lcm of active GCDs 
    // because the final array would have to satisfy all of them
    for(int i=1; i<=N; i++) {
        int x = 1;
        for(int j=1; j<=16; j++) {
            dif[j][i] += dif[j][i-1];
            if(dif[j][i]>0) x = lcm(x, j);
        }
        st[0][i] = x;
    }

    // build rest of gcd sparse table
    for(int i=1; i<LOG; i++)
        for(int j=1; j+(1<<i)-1<=N; j++)
            st[i][j] = __gcd(st[i-1][j], st[i-1][j+(1<<i-1)]);
    

    for(int i=1; i<=M; i++){
        int g = gcdQuery(x[i], y[i]);
        if(g != z[i]) { cout << "Impossible\n"; return 0;}
    }
    for(int i=1; i<=N; i++)
        cout << st[0][i] << " ";
    cout << endl;
}