#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int arr[s.length()+1][2] = {0};
    for (int i = 1; i <= s.length(); i++) {
        arr[i][0] = arr[i-1][0];
        arr[i][1] = arr[i-1][1];
        if (s[i-1] == '0') arr[i][0]++;
        else arr[i][1]++;
        //cout << i << ": " << arr[i][0] << " " << arr[i][1] << endl;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;   
        int pos = lower_bound(arr, arr+s.length()+1, arr[]);
        if (pos < 0) cout << -1;
        else cout << pos;
    }


    /*
    string s; cin >> s;
    int arr[s.length()+1][2] = {0};
    for (int i = 1; i <= s.length(); i++) {
        arr[i][0] = arr[i-1][0];
        arr[i][1] = arr[i-1][1];
        if (s[i-1] == '0') arr[i][0]++;
        else arr[i][1]++;
        //cout << i << ": " << arr[i][0] << " " << arr[i][1] << endl;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;

        for (int j = 0; j < s.length()-a; j++) {
            if (arr[a+j][c-'0'] - arr[a-1][c-'0'] == b){
                cout << j+1 << endl;
                break;
            }
            if (j == s.length()-a-1) cout << -1 << endl;
        }
    }
    */
}
