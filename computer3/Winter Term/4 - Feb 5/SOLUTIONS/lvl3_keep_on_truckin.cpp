#include <bits/stdc++.h>
using namespace std;
int A, B, m; vector<int> pos={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
long long dp[40];
int main(){
    cin >> A >> B >> m;
    for(int i=0, x; i<m; i++){
        cin >> x; pos.push_back(x);
    }
    sort(pos.begin(), pos.end());  dp[0] = 1;
    for(int i=1; i<pos.size(); i++){
        for(int j=i-1; j>=0; j--){
            int dis = pos[i] - pos[j];
            if(dis >= A && dis <= B) dp[i] += dp[j];
        }
    }
    cout << dp[pos.size()-1] << "\n";
}