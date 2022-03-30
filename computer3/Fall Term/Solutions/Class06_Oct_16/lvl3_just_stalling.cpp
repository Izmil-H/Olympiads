#include <bits/stdc++.h>
using namespace std;
int n; long long ans=1;
int main(){
    cin >> n;
    vector<int> cow(n), stall(n);
    for(int i=0; i<n; i++) {
        cin >> cow[i];
    }
    for(int i=0; i<n; i++) {
        cin >> stall[i];
    }
    sort(cow.begin(), cow.end());
    sort(stall.begin(), stall.end());
    for(int i=n-1; i>=0; i--){
        int cnt = 0;
        for(int j=i; j>=0; j--) {
            if(stall[j] >= cow[i]) cnt++;
        }
        ans *= cnt;
    }
    cout << ans << endl;
}