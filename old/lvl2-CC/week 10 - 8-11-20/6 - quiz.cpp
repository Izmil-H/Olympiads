#include<bits/stdc++.h>
using namespace std;

bool sorter(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    int n, b;
    cin >> n >> b;
    pair<int, int> arr[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;   
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) { // discounted item
        arr[i].first /= 2;
        pair<int, int> tmp[n];
        copy(arr, arr+n, tmp);
        sort(tmp, tmp+n, sorter);
        int cnt = 0, rem = b;
        for (int j = 0; j < n; ++j) {
            if (rem >= tmp[j].first + tmp[i].second) {
                cnt++;
                rem -= tmp[j].first + tmp[i].second;
            }
        }
        ans = max(ans, cnt);
        arr[i].first *= 2;
    }
    cout << ans;
}






/*
bool sorter(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first + a.second < b.first + b.second;
}

int main(){ 
    int n, b;
    cin >> n >> b;
    pair<int, int> arr[n];
    int sumArr[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        sumArr[i] = sum + arr[i].first + arr[i].second;
        sum += arr[i].first + arr[i].second;
    }
    //sort(arr, arr+n, sorter);

    int large = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (sumArr[j]-(arr[i].first)/2 <= b) {
                count++;
            }
        }
        if (count > large) large = count;
    }
    cout << large;
}
*/