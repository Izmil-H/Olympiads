#include<bits/stdc++.h>
using namespace std;

int main() {
    //for (int t = 0; t < 5; ++t) {
        int n;
        cin >> n;
        bool state[n+1] = {0};
        int pos[n];
        
        for(int i = 0; i < n; ++i) {
            cin >> pos[i];
        }

        bool impos = false;
        for(int i = 0; i < n; ++i) {
            int idx = n-pos[i];
            
            while(true) {
                if (state[idx] == 0) {
                    pos[i] = idx;
                    state[idx] = 1;
                    break;
                } else idx--;
                if (idx == 0)  {
                    impos = true;
                    break;
                }
            }
            if (impos) break;
        }

        if (impos) {
            cout << "IMPOSSIBLE";
        } else  {
            for (int i = 0; i < n; ++i) {
                cout << pos[i] << " ";
            }
        }
        cout << endl;
    //}
}