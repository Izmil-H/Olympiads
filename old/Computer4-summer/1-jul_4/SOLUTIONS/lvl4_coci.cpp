#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 655;
int N, s[MM][MM], mx = 651;
int main(){
    cin >> N;  vector<int> a(N+1), b(N+1);
    for(int i=1; i<=N; i++) {
        cin >> a[i] >> b[i];   a[i]++; b[i]++; s[a[i]][b[i]]++;
    }
    for(int i=1; i<=mx; i++)
        for(int j=1; j<=mx; j++)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    for(int i=1; i<=N; i++) {
        int best = s[mx][mx] - s[mx][b[i]] - s[a[i]][mx] + s[a[i]][b[i]];
        int worst = s[a[i]-1][b[i]-1];
        if(a[i] == mx) worst += s[1][b[i]] - s[1][b[i]-1];
        if(b[i] == mx) worst += s[a[i]][1] - s[a[i]-1][1];
        cout << best + 1 << " " << (N-worst) << "\n";
    }
}