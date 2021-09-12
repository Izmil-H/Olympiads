#include<bits/stdc++.h>
using namespace std;
int T, n; deque<int> a;
bool fun(deque<int> a, int st){
    deque<int> dest;
    if(st == 0) { dest.push_back(a.front()); a.pop_front(); }
    else { dest.push_back(a.back()); a.pop_back(); }
    while(!a.empty()){
        if(a.front() == dest.front() - 1) {
            dest.push_front(a.front()); a.pop_front();
        }else if(a.front() == dest.back() + 1) {
            dest.push_back(a.front()); a.pop_front();
        }else if(a.back() == dest.front()-1) {
            dest.push_front(a.back()); a.pop_back();
        }else if(a.back() == dest.back() + 1){
            dest.push_back(a.back()); a.pop_back();
        }else return false;
    }
    return true;
}
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> n;  a.clear();
        for(int i=1, x; i<=n; i++){
            cin >> x; a.push_back(x);
        }
        if(fun(a, 0) || fun(a, 1))
            cout << "Case #" << t << ": yes\n";
        else
            cout << "Case #" << t << ": no\n";
    }
}