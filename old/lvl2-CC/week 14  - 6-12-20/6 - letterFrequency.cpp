#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    int arr[s.length()+1][26] = {0}; 
    int sum[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 26; j++) arr[i+1][j] = sum[j];
        if (s[i] != ' '){
            arr[i+1][s[i]-'a']++;
            sum[s[i]-'a']++;
        }
        //cout << i << ": "; for (int j = 0; j < 26; j++) cout << arr[i][j] << " "; cout << endl;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        //cout << arr[b][c-'a'] << " " << arr[a-1][c-'a'] << " ";
        //cout << b << " " << a-1 << " ";
        cout << arr[b][c-'a'] - arr[a-1][c-'a'] << endl;
    }
}