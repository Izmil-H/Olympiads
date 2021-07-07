#include<bits/stdc++.h>
using namespace std; 

/* --- MY IDEA --- 
bool comp (pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

int main () {
    int n, t;
    cin >> n >> t;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+n, comp);
    for (int i = 0; i < n; i++) {
        if (arr[i].first <= t) {
            cout << arr[i].second;
            break;
        }
    }
}
*/

// --- BETTER IDEA --- 
int main() {
    int n, t;
    cin >> n >> t;
    int best = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= t) best = max(best, b);
    }
    cout << best;
}