#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, pre[(1<<23)+20]; deque< pair<ll, int> > Q; ll x; stack<int> st;
int main(){
    scanf("%d %d", &N, &K);
    Q.push_back({0, 0});
    for(int i=1; i<=N+1; i++){
        if(i<=N) scanf("%lld", &x);
        else x = 0;
        while(!Q.empty() && i - Q.front().second > K) Q.pop_front();
        pre[i] = Q.front().second;
        ll val = Q.front().first + x;
        while(!Q.empty() && val <= Q.back().first) Q.pop_back();
        Q.push_back({val, i});
    }
    printf("%lld\n", Q.back().first);
    for(int i=N+1; pre[i]; i=pre[i])
        st.push(pre[i]);
    while(!st.empty()){
        printf("%d ", st.top()); st.pop();
    }
}