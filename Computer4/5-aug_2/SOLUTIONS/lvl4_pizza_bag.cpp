#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+2;
int N, K; ll psa[2*MM], ans; deque<int> dq;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> psa[i]; psa[i+N] = psa[i];
    }
    dq.push_back(0);
    for(int i=1; i<=2*N; i++){
        psa[i] += psa[i-1];
        while(!dq.empty() && psa[dq.back()] > psa[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() && dq.front() < i-K) dq.pop_front();
        ans = max(ans, psa[i] - psa[dq.front()]);
    }
    cout << ans << endl;
}