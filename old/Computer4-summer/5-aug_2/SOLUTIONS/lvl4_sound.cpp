#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, C; deque<pii> minQ, maxQ; bool flag;
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &C);
    for(int i=1, x; i<=N; i++){
        scanf("%d", &x);
        while(!minQ.empty() && minQ.front().second <= i-M) minQ.pop_front();
        while(!maxQ.empty() && maxQ.front().second <= i-M) maxQ.pop_front();
        while(!minQ.empty() && minQ.back().first >= x) minQ.pop_back();
        while(!maxQ.empty() && maxQ.back().first <= x) maxQ.pop_back();
        minQ.push_back({x, i}); maxQ.push_back({x, i});
        if(i >= M && maxQ.front().first - minQ.front().first <= C){
            flag = 1; printf("%d\n", i-M+1);
        }
    }
    if(!flag) printf("NONE\n");
}