#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n+2];
    int sumArr[n+2] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sumArr[i] = sumArr[i-1] + arr[i];
    }
    //for(int i = 0; i < n+2; ++i) cout << sumArr[i] << " ";
    int ans = 0;
    for (int l = 1, r = 1; r <= n; ++r) {
        //cout << l << " " << r << " " << sumArr[r] - sumArr[l-1] << " " << ans << endl;
        while(sumArr[r] - sumArr[l-1] >= m) {
            l++;
            //cout << l << " " << r << " " << sumArr[r] - sumArr[l-1] << " " << ans << endl;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}
    /*
    int n, m;
    cin >> n >> m;
    int arr[n]; cin >> arr[0];
    int sumArr[n]; sumArr[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        sumArr[i] = sumArr[i-1] + arr[i];
    }

    int large = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j + i <= n; ++j) {
            int sum = sumArr[i + j - 1] - sumArr[i] + arr[i];
            if (sum < m) large = max(large, j);
            //cout << i << " " << j << " " << sum << " " << large << endl;
        }
    }   
    cout << large;
    */

    /*
    int n;
    long long m;
    cin >> n >> m;
    int arr[n];
    cin >> arr[0];
    long long sumArr[n] = {0};
    sumArr[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        cin >> arr[i];
        sumArr[i] = sumArr[i-1] + arr[i];
    }

    int large = 0;
    for (int i = 0; i < n; ++i) { //starting points
        cout << i << ":" << endl;
        for (int j = 0; j < n - i; ++j) { // size
            large = max(large, j+1);
            if (sumArr[i+j] - sumArr[i] + arr[i] >= m) {
                large = max(large, j);
                break;
            }
            cout << "  " << j << " " << sumArr[i+j]-sumArr[i]+arr[i] << " " << large << endl;
        }
    }
    cout << large;
    */