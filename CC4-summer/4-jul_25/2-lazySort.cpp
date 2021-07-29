#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define PB push_back
#define F first
#define S second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,is,ie,in) for(int i=is; i<ie; i+=in)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}


int main() {
    int t, n, x; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n; deque<int> og, im;
        fo(i,n) { cin >> x; og.push_front(x); }
        im.PB(og.back()); og.pop_back();
        
        cout << "Case #" << tc << ": ";
        bool flg = 0;  
        while (true) {
            if (im.front()-1 == og.front()) {
                im.push_front(og.front()); og.pop_front();
            } else if (im.front()-1 == og.back()) {
                im.push_front(og.back()); og.pop_back();
            } else if (im.back()+1 == og.front()) {
                im.push_back(og.front()); og.pop_front();
            } else if (im.back()+1 == og.back()) {
                im.push_back(og.back()); og.pop_back();
            } else {
                if (og.size()) flg = 1; 
                break;
            }
        }
        if (flg) cout << "no\n";
        else cout << "yes\n";
    }
}