#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
#define pii pair<int,int>

const int MM = 1e5+2, INF = 0x3f3f3f3f;
int N, M, J, givenT[MM], t[MM], sol = INF;

int main() {
    cin >> N >> M >> J;
    memset(t, 0x3f, sizeof(t)); t[0] = 0;
    memset(givenT, 0x3f, sizeof(givenT)); givenT[0] = 0;

    for(int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        givenT[a] = b;
    }
    
    deque<int> q; q.push_back(0);
    for(int i = 1; i <= N; i++) {
        while (q.size() && i - J > q[0]) q.pop_front();
        t[i] = max(t[q[0]], givenT[i]);
        while(q.size() && t[i] <= t[q.back()]) q.pop_back();
        q.push_back(i);
        
    }
    Fo(i, N-J+1, N+1, 1) sol = min(sol, t[i]);
    cout << (sol == INF? -1: sol) << endl;
}