#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    bool chair[n+1] = {0}; 
    for (int i = 1, x; i <= k; i++) {
        cin >> x;
        chair[x] = 1;
    }
    int stud[n+1] = {0};
    for (int i = 1, x; i <= k+1; i++) {
        cin >> x; 
        stud[x] = i;
    }

    stack<int> stk;
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= n; i++) {
            if (stud[i] != 0) {
                stk.push(stud[i]);
                stud[i] = 0;
            }
            if (chair[i]) {
                if (!stk.empty()) {
                    stk.pop();
                    chair[i] = 0;
                }
            }
        }
    }
    cout << stk.top();
}