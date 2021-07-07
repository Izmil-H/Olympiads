#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string scarf;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        scarf += c;
    }

    int large = 0;
    for (int i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b;
        int l = scarf.find(a);
        int r = scarf.rfind(b);
        large = max(large, r-l+1);
        //cout << a << " " << b << " " << l << " " << r << " " << large << endl;
    }
    cout << large;
}