#include<bits/stdc++.h>
using namespace std;

int main() {
    int te; cin >> te;
    for (int t = 0; t < te; ++t) {
        int n; cin >> n; 
        vector<int> train;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            train.push_back(x);
        }
        int need = 1;
        vector<int> stck;
        stck.push_back(0);
        while (true) {
            cout  << need << " " << train.back() << " \n";
            for (int j = 0; j < stck.size(); ++j) {
                cout << "   :" << stck.back() << endl;  
                if (stck.back() == need) {
                    cout << 'b' << endl;
                    need++;
                    stck.erase(stck.end());
                } else break;
            }
            if (train.back() == need) {
                cout << 'a' << endl;
                need++;
                train.erase(train.end());
            } else {
                cout << 'c' << endl;
                stck.push_back(train.back());
                train.erase(train.end());
            }
        }
        if (need == n) cout << "Y" << endl;
        else cout << "N" << endl;
        cout << "-----------" << endl;
    }
}

