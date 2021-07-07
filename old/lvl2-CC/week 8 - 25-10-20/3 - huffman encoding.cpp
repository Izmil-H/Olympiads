#include<bits/stdc++.h>
using namespace std;


int main() {
    int k; cin >> k;
    pair<char, string> arr[k];
    for (int i = 0; i < k; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    string s; cin >> s;

    string ans = "";
    while (s.length() > 0) {
        for (int i = 0; i < k; ++i) { // for each letter check if its the first
            if (s.find(arr[i].second) == 0) {
//                cout << i << ":" << arr[i].second << ":" << s << ":" << s.length() << ":";
                ans += arr[i].first;
                s.erase(0, arr[i].second.length());
//                cout << s.length() << endl;
                break;
            }
        }
    }
    cout << ans;

}