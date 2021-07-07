#include<bits/stdc++.h>
using namespace std;

void tower(int d, char from, char spare, char to) {
    if (d == 1) {
        cout << from << to << endl;
    } else {
        tower(d-1, from, to, spare);
        cout << from << to << endl;
        tower(d-1, spare, from, to);
    }
}

int main() {
    int n;
    cin >> n;
    tower(n, 'A', 'B', 'C');
}