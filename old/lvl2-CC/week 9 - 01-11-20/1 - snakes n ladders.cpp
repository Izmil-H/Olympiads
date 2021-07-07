#include<bits/stdc++.h>
using namespace std;

int main() {
    int pos = 1;
    int dice;
    do {
        cin >> dice;
        if (dice == 0) {
            cout << "You Quit!";
            break;
        }
        if (pos + dice <= 100) pos += dice;

        switch(pos) {
            case 99: pos = 77; break;
            case 90: pos = 48; break;
            case 67: pos = 86; break;
            case 54: pos = 19; break; 
            case 40: pos = 64; break;
            case 9: pos = 34; break;
        }

        cout << "You are now on square " << pos << endl;
        if (pos == 100) {
            cout << "You Win!";
            break;
        }

    } while (pos != 100);

}