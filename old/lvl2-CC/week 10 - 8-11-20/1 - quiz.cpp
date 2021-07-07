#include<bits/stdc++.h>
using namespace std; 

int main() {
    int n;
    cin >> n;
    string s;
    int cat = 0, dog = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "cats") cat++;
        else dog++;
    }
    if (cat > dog) cout << "cats";
    else if (cat < dog) cout << "dogs";
    else cout << "equal";
}