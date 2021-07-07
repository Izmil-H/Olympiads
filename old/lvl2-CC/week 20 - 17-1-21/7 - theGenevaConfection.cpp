#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int needed = 1;
    stack<int> stk;
    int cnt = 0;
    bool ans = true;
    for (int i = n-1; i >= 0; ) {
        cout << i << " " << arr[i] << " " << needed << " ";
        if (arr[i] != needed) {
            if (!stk.empty() && stk.top() != needed) {
                cout << "push";
                stk.push(arr[i]);
                i--;
            } else if (stk.top() == needed) {
                stk.pop();
                cout << "stk";
                needed++;
            }
        } else {
            cout << "arr";
            needed++;
            i--;
        }
        cout << endl;
        cnt++;
        if (cnt == 50) {
            break;
        }
    }
    if (ans) cout << "yes";
    else cout << "no";
}