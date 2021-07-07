#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;

ll fun(ll x) {
    if (x > N) return 0;
    return fun(x*10 + 2) + fun(x*10 + 3) + 1;
}

int main() {
    cin >> N;
    cout << fun(0) -1  << endl
}


int main() {
    int n;
    cin >> n;
    vector<int> ans;
    for (auto it: ans) { //double check syntax
        long int num = ans[it]*10 + 2;
        if (num > n) {
            break;
        }
        ans.push_back(num);
        num = ans[it]*10 + 3;
        if (num > n) {
            break;
        } 
        ans.push_back(num); 
    }
}

/*
int main() {
    int n;
    cin >> n;
    string s = to_string(n);
    cout << s << endl;

    int ans = 0;
    for (int i = 1; i <= s.length(); ++i) {
        ans += pow(2, i);
        cout << i << ':' << ans << endl;
    }
    
    int threes = 0;
    bool full = false;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] - '0' < 2) {
            ans -= pow(2, s.length());
            break;
        }
        if (s[i] - '0' > 2) {
            threes++;
            full = true;    
        }
    }
    if (full) {
        ans+= pow(2, threes);
    }
    cout << ans;
} 
*/