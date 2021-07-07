#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    for (cin >> t;  t--;) {
        int n; cin >> n;
        int arr[n];
        vector<int> cand;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
            cand.push_back(arr[i]);
            for (int j = 0; j < i; j++) {
                cand.push_back(abs(arr[i]-arr[j]));
            }
        }
        sort(cand.begin(), cand.end());
        cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
        int ans = 0;
        for (int i = 0; i < cand.size(); i++) {
            for (int j = i; j < cand.size(); j++) {
                for (int k = j; k < cand.size(); k++) {
                    int a = cand[i], b = cand[j], c = cand[k];
                    vector<int> tmp = {a,b,c, a+b, a+c, b+c, a+b+c}; bool flag = true;
                    for (int l = 0; l < n; l++) {
                        if (find(tmp.begin(), tmp.end(), arr[l]) == tmp.end()) flag = false;
                    }
                    if (flag) ans++;
                }
            }
        }
        cout << ans << endl;
    }
}