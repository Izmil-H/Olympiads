#include<bits/stdc++.h>
using namespace std;

bool sortByInd(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == -1) return 0;
    if (b.second == -1) return 1;
    return a.second < b.second;
}

int main() {

    for (int l = 0; l < 5; ++l) {
        string s;
        getline(cin, s);
        string ans = "";

       

        for (int i = 0; i < 3; ++i) { 
            pair<string, int> arr[4];
            arr[0].first = "/*"; arr[0].second = s.find("/*");
            arr[1].first = "\""; arr[1].second = s.find("\"");
            arr[2].first = "\'"; arr[2].second = s.find("\'");
            arr[3].first = "//"; arr[3].second = s.find("//");
            sort(arr, arr+3, sortByInd);
//            for (int i = 0; i < 4; ++i) cout << arr[i].first << " " << arr[i].second << endl;
            
            if (arr[i].second == -1) break;
            int idx = s.find(arr[i].first);
            
            if (arr[i].first == "/*") {
//                cout << idx  << " " << s.find("*/", idx+1) << endl;
                ans += s.substr(idx + 2, s.find("*/", idx+1) - idx - 2);
                s.erase(idx, s.find("*/", idx+1) - idx);
            }

            if (arr[i].first == "\"") {
//                cout << idx  << " " << s.find("\"", idx+1) << endl;
                ans += s.substr(idx + 1, s.find("\"", idx+1) - idx - 1);
                s.erase(idx, s.find("\"", idx+1) - idx);
            }

            if (arr[i].first == "\'") {
//                cout << idx  << " " << s.find("\'", idx+1) << endl;
                ans += s.substr(idx + 1, s.find("\'", idx+1)- idx- 1);
                s.erase(idx, s.find("\'", idx+1) - idx);
            }
            
            if (arr[i].first == "//") {
                ans += s.substr(idx + 2, s.length() - idx - 2);
                s.erase(idx, s.length() - idx);
            }
            ans += " ";
        }
        
        cout << ans << endl;
    }


/*
    for (int l = 0; l < 5; ++l) {
        string s;
        getline(cin, s);
        bool text = false;
        string ans = "";
        string end;
        for (int i = 0; i < s.length(); ++i) {
            if (text) {
                if (s[i] == end[0]) {

                }
                ans += s[i];
                continue;
            }
            if (s[i] == '/') {
                if (s[i+1] == '/') {
                    ans += s.substr(i+2, s.length()- i-2);
                    break;
                } else if (s[i+1] == '*') {
                    text = true;
                    end = "*\"";
                }
            } else if (s[i] == '\'') {
                text = true;
                end = "\'";
            }
        }
    }
    */
}