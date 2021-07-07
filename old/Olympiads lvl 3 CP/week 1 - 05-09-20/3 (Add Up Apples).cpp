#include<bits/stdc++.h>
using namespace std;
int n, count=0;

void fun(int last, int sum, string ans) {
    if (sum == n) {
        count++;
        cout << ans << endl;
        return;
    }
    for (int cur=last; cur+sum<=n; cur++) {
        fun(cur, sum+cur, ans+"+"+to_string(cur));
    }
}

int main() {
    cin >> n; 
    for (int i = 0; i < n/2; i++) {
        fun(i, i, to_string(n) + "=" + i);
    }
}