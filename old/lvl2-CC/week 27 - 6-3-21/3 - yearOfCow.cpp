#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string,int> anml = {{"Ox",0}, {"Tiger",1}, {"Rabbit",2},
                      {"Dragon",3}, {"Snake",4}, {"Horse",5}, {"Goat",6}, 
                      {"Monkey",7}, {"Rooster",8}, {"Dog",9}, {"Pig",10}, {"Rat",11}};
    map<string, string> yr;
    map<string, int> age;
    for (int i= 0; i < n; i++) {
        string sntc[8];
        for (int j = 0; j < 8; j++) cin >> sntc[j];
        string y = yr[sntc[7]];
        int id = anml[y];
        if (s[3] == "previous") {
        }
    }
}