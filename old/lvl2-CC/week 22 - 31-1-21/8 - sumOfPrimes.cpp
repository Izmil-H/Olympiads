#include<bits/stdc++.h>
using namespace std;

const int len = 1e7;
bool prime[len + 1] = {0};

int main() {
    for (int i = 2; i <= len; i++) {
        if (!prime[i]) {
            for (int j = i+i; j <= len; j+=i) {
                prime[j] = true;
            }
        }
    }


    int t = 5, n;
    while (t--) {
        cin >> n;
        cout << n << " = ";
        if (!prime[n]) cout << n;
        else if (n % 2 == 0){
            for (int p = n/2; p >= 3; p--) {
                if (!prime[p] && !prime[n-p]) {
                    cout << p << " + " << n-p;
                    break;
                }
            }
        } else {
            bool flag = false;
            for (int p = n/3; p >= 3; p--) {
                if (prime[p]) continue;
                int x = n-p;
                for (int q = x/2; q >= p; q--) {
                    if (!prime[q] && !prime[x-q]) {
                        cout << p << " + " << q << " + " << x-q;
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        cout << endl;
    }
}


/*
const int len = 1e7;
bool prime[len + 1] = {0};

int main() {
    for (int i = 2; i <= len; i++) {
        if (!prime[i]) {
            for (int j = i+i; j <= len; j+=i) {
                prime[j] = 1;
            }
        }
    }

    int t = 5;
    while (t--) {
        int n; cin >> n;

        cout << n << " = ";

        if (!prime[n]) {
            cout << n << endl;
        } else {
            bool flag = false;
            for (int i = n/2; i > 2; i--) {
                if (!prime[i] && !prime[n-i]) {
                    cout << i << " + " << n-i << endl;
                    flag = true;
                }
                if (flag) break;
            }
            if (flag) continue;
            for (int i = n/3 ; i > 2; i--) {
                if (!prime[i]) {
                    for (int j = ceil((n-i)/2.0); j > 2; j--) {
                        if (!prime[j] && !prime[n-i-j]) {
                            cout << i << " + " << j << " + " << n-i-j << endl;
                            flag = true;
                        }
                        if (flag) break;
                    }   
                }
                if (flag) break;
            }
        }
    }
}
*/