#include<bits/stdc++.h>
using namespace std;


class sugg{
public:
    char a;
    int x;
    int in;
    sugg(){};
    sugg(char letter, int appearance, int index){
        a = letter; x = appearance; in = index;
    }
};

bool sortByEnd(sugg const & s1, sugg const & s2) {
    return s1.in < s2.in;
}

int main() {
    int n, m;
    cin >> n >> m;
    sugg arr[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].a >> arr[i].x >> arr[i].in;
        
    }
    sort(arr, arr+m, sortByEnd);
    pair<int, int> freqStart[26];


    string ans = "";
    bool works = true;
    for (int i = 0; i < m; ++i) {
        int idx = arr[i].a - 'a'; 
        if (arr[i].x > freq[idx]) {
            int diff = arr[i].x - freq[idx];
            freq[idx] += diff;
            for (int j = 0; j < diff; ++j) {
                ans += arr[i].a;
            }
        }
        if (ans.length() > arr[i].in) {
            cout << -1;
            works = false;
            break;
        }
    }   
    if (works) cout << ans << endl;
}





/*
class sugg{
public:
    char a;
    int x;
    int in;
    sugg(){};
    sugg(char letter, int appearance, int index){
        a = letter; x = appearance; in = index;
    }
};

bool sortByEnd(sugg const & s1, sugg const & s2) {
    return s1.in < s2.in;
}

int main() {
    int n, m;
    cin >> n >> m;
    sugg arr[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr[i].a >> arr[i].x >> arr[i].in;
        
    }
    sort(arr, arr+m, sortByEnd);
    int freq[26] = {0};


    string ans = "";
    bool works = true;
    for (int i = 0; i < m; ++i) {
        int idx = arr[i].a - 'a'; 
        if (arr[i].x > freq[idx]) {
            int diff = arr[i].x - freq[idx];
            freq[idx] += diff;
            for (int j = 0; j < diff; ++j) {
                ans += arr[i].a;
            }
        }
        if (ans.length() > arr[i].in) {
            cout << -1;
            works = false;
            break;
        }
    }   
    if (works) cout << ans << endl;
}
*/
