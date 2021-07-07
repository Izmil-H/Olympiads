#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<double> strms;
    for (int i = 0; i < n; i++){ 
        int x; cin >> x;
        strms.push_back(x);
    }

    int m;
    while (true) {
        //for (auto x: strms) cout << x << " "; cout << endl;
        
        cin >> m;
        if (m == 77) break;
        int a; cin >> a; a--;
        
        if (m == 99) {
            int b; cin >> b;
            strms.push_back(strms.at(a) * double(100.0-b)/100.0);
            strms.at(a) *= double(b)/100.0;
        } else {
            strms.at(a+1) += strms.at(a);
            strms.erase(strms.begin()+a);
        }

        sort(strms.begin(), strms.end());
    } 
    for (auto x : strms) {
        cout << round(x) << " ";
    }
}