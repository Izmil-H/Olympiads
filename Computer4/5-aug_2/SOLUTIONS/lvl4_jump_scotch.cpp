#include <bits/stdc++.h>
using namespace std;
int n, d, x; deque< pair<int, int> > Q;
int main(){
    scanf("%d %d %d", &n, &d, &x);
    Q.push_back(make_pair(x, 1));
    for(int i=2; i<=n; i++){
        scanf("%d", &x);
        while(i-Q.front().second > d) Q.pop_front();
        x += Q.front().first;
        while(Q.back().first >= x) Q.pop_back();
        Q.push_back(make_pair(x, i));
    }
    printf("%d\n", Q.back().first);
}