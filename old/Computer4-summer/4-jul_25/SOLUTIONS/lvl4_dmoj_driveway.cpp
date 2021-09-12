#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, M; deque<string> q; string name, op;
int main(){
    cin >> T >> M;
    for(int i=1; i<=T; i++){
        cin >> name >> op;
        if(op=="in") {
            q.push_back(name);
        }else {
            if(q.empty()) continue;
            if(name == q.back()) q.pop_back();
            else if(name == q.front() && M > 0){
                q.pop_front(); M--;
            }
        }
    }
    for(auto x : q) cout << x << "\n";
}