#include<bits/stdc++.h>
using namespace std;

int main() {
    long long left = 1, right = 2000000000, mid = right/2;
    int count = 0;
    while(true) {
        cout << mid << endl; cout.flush();
        count++;
        string status; cin >> status;
        if (status == "SINKS"){
            left = mid+1;
            mid = (mid+right+1)/2;
        } else if (status == "FLOATS") {
            right = mid-1;
            mid = (mid+left)/2;
        } else break;
    }
    //cout << count;
}

