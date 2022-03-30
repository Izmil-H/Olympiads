#include <bits/stdc++.h>
using namespace std;
int n, id[10], sour[10], bit[10], ans = 2e9; vector<int> res;
void getComb(int idx, int id[], vector<int>& res){
    if(idx == n){
        if(res.empty()) return;
        int totSour = 1, totBit = 0;
        for(int x: res){ totSour *= sour[x];  totBit += bit[x]; }
        ans = min(ans, abs(totSour - totBit));
        return;
    }
    getComb(idx+1, id, res);
    res.push_back(id[idx]); getComb(idx+1, id, res); res.pop_back();
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> sour[i] >> bit[i]; id[i] = i;
    }
    getComb(0, id, res);
    cout << ans << endl;
}