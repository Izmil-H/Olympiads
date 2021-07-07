#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string words[n];
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    cout << words[0];
    int count = words[0].length();
    for (int i = 1; i < n; ++i) {
        if (count + words[i].length() > k) {
            count = words[i].length();
            cout << endl << words[i];
        } else {
            count += words[i].length();
            cout << " " << words[i];
        }
    }
}