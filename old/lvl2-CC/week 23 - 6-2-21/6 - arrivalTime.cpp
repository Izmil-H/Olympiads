#include<bits/stdc++.h>
using namespace std;

void time (int& hour, int& min) {
    if (min >= 60) {
        hour++; min -= 60;
    }
    if (hour >= 24) {
        hour -= 24;
    }
}

int main() {
    int h, m;
    cin >> h; cin.ignore(); cin >> m;
    
    for (int i = 0; i < 120; i++) {
        m++;
        if ( (h >= 7 && h < 10) || (h >= 15 && h < 19) ) {
            m++;
        }        
        time(h, m);
    }
    cout << setfill('0') << setw(2) << h << ":" 
         << setfill('0') << setw(2) << m;
}