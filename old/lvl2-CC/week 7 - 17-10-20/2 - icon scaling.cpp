#include<bits/stdc++.h>
using namespace std;

int main() {
    char arr[3][3] = {
        {'*', 'x', '*'},
        {' ', 'x', 'x'},
        {'*', ' ', '*'} };

    int k;
    cin >> k;

    for (int i = 0; i < 3; ++i) { // each row of original grid
        for (int j = 0; j < k; ++j) { // print row k times
            for (int l = 0; l < 3; ++l) { // each col of original grid
                for (int m = 0; m < k; ++m) { // print col k times
                    cout << arr[i][l];
                }
            }
            cout << endl;
        }
    }
}