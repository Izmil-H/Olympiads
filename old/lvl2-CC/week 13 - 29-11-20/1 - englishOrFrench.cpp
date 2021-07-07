#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    int t = 0, s = 0;
    for (int l = 0; l < n; ++l) {
        string line;
        getline(cin, line);
        for(int i = 0; i < line.length(); ++i) {
            if (tolower(line[i]) == 't') t++;
            else if (tolower(line[i]) == 's') s++;
        }
    }
    if (s >= t) cout << "French";
    else cout << "English";
}