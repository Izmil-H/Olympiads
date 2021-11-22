#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define IM INT_MAX 
#define LLM LLONG_MAX
#define pi pair<int,int>
#define pl pair<ll,ll>
#define mi map<int,int>
#define ml map<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define pb push_back
#define fi first
#define si second
#define fo(i,n) for(int i=0; i<n; i++)
#define Fo(i,n) for(int i=1; i<=n; i++)
#define aIN(n,arr) fo(i,n){cin>>arr[i];}
const int MS = 1e5+2;

int n, idx; 
string s; vector<string> words[5];

bool ispunct(char c) {
    return (c == '.' || c == '!' || c == '?');
}
bool check(string word) {
    bool first = 0, rest = 1;
    if (isupper(s[0])) first = 1;
    for(int i = 1; i < s.size(); i++) {
        if (!islower(s[0])) rest = 0;
    }
    cout << s << " " << first << " " << rest << endl;
    return (first && rest);
}

int main() {
    cin >> n; cin.ignore(); getline(cin, s);
    words[0].pb("");
    fo(i, s.size()) {
        if (s[i] == ' ') {
            (words[idx]).pb("");
        } else {
            if (ispunct(s[i])) idx++;
            else words[idx].back().pb(s[i]);
        }
    }
    fo(i,n) {
        int ans = 0;
        for(string word: words[i]) ans += check(word);
        cout << ans << endl;
    }
}