#include<bits/stdc++.h>
using namespace std;

int main() { 
    int n, l;
    cin >> n >> l;
    string s;
    vector<pair<int,int>> pals[n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < l; j++) { // middle point
            for (int k = 0; k <= min(l-j-1, j); k++) {
                //cout << j-k << " " << j << " " << j+k << endl;
                if (s[j-k] != s[j+k]) break;
                pals[i].push_back({j-k,j+k});
            }
            /*
            for (int k = 0; k <= min(l-j-2, j); k++) {
                if (s[j-k] != s[j+k+1]) break;
                pals[i].push_back({j-k,j+k+1});
            }
            for (int k = 0; k <= min(l-j-1, j-1); k++) {
                if (s[j-k-1] != s[j+k]) break;
                pals[i].push_back({j-k-1,j+k});
            }
            */
        }
        for (auto x: pals[i]) cout << x.first << "," << x.second << "  "; cout << endl;
    }
}