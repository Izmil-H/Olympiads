#include<bits/stdc++.h>
using namespace std;

int main() {
    double n; int m, k;
    cin >> n >> m >> k;
    int t[k]; double pct[k];
    for (int i = 0; i < k; ++i) {
        cin >> t[i] >> pct[i];
        pct[i] = (100.0 - pct[i])/100.0;
    }

    int maxT = 100000, dif[maxT+2] = {0};
    for(int i = 1; i<= m; ++i) {
        int s, len, x;
        cin >> s >> len >> x;
        dif[s] += x; dif[s+len] -= x;
    }
    for(int i = 0; i <= maxT; ++i) {
        if (i > 0) dif[i] += dif[i-1];
        if(dif[i] == 0) continue;
        double mins = dif[i];
        for (int j= 0; j < k; ++j) {
            if (t[j] >= dif[i]) {
                mins = 0; break;
            }
            else {
                mins = min(mins, (dif[i]-t[j])*pct[j]); 
            }
        }
        n -= mins;
    }
    if (n <= 0) cout << "Act Like A Cactus."; 
    else cout << fixed << setprecision(2) << n;
}
    /*
    int n, m, k;
    cin >> n >> m >> k;
    int armr[k][2];
    for (int i = 0; i < k; ++i) {
        cin >> armr[i][0] >> armr[i][1];    
    }
    
    int t = 10000 + 1;
    int damg[t] = {0};
    int bad[m][3];
    for (int i = 0; i < m; ++i) {
        cin >> bad[i][0] >> bad[i][1] >> bad[i][2];
        damg[bad[i][0] + 1] += bad[i][2]; 
        damg[bad[i][0] + bad[i][1] + 1] -= bad[i][2];
    }
    
    float total = 0;
    for(int i = 1; i < t; ++i) {
        damg[i] += damg[i-1];
        //cout << damg[i] << " ";
        float best = n;
        for (int j = 0; j < k; ++j) {  
            best = min(best, (1 - armr[j][1]/float(100))*(damg[i] - armr[j][0]));
            if (best < 0) best = 0;
            //cout << damg[i] << " " << best << " ";
        }
        //cout << endl;
        total += best;
    }
    if (total >= n) cout << "Act Like A Cactus.";
    else cout << fixed <<setprecision(2) << 100 - total;
    */