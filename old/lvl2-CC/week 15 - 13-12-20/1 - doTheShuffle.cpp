#include<bits/stdc++.h>
using namespace std;

int main() {
    string list = "ABCDE";
    bool flag = true;
    while (flag) {
        int b, n;
        cin >> b >> n;
        for (int i = 0; i < n; i++) {
            if (b == 1) {
                list += list[0];
                list.erase(0,1);                
            } else if (b == 2) {
                list.insert(0, 1, list[4]);
                list.erase(5);
            } else if (b == 3) {
                list.insert(2, 1, list[0]);
                list.erase(0, 1);
                
            } else {
                for (int j = 0; j < 5; j++) cout << list[j] << " ";
                cout << endl;
                flag = false;
                break;
            }
            //cout << list << endl;
        }
    }
}