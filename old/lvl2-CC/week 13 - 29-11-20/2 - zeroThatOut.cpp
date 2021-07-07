#include<bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    vector<int> vec;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        sum += x;
        vec.push_back(x);
        if (x == 0) {
            vec.erase(vec.end()-1);
            sum -= vec.back();
            vec.erase(vec.end()-1);
        }
    }
    cout << sum;
}