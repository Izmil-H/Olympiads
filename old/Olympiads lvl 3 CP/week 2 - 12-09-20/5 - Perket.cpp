#include<bits/stdc++.h>
using namespace std;

int id[10], sour[10], bit[10], ans=INT_MAX; vector<int> res;

void comb(int idx, int id[], vector<int> res) {
    if (idx == 1) {
        if(res.empty()) return;
        int totSour = 1, totBit = 0;
        for (int x: res) { totSour *= sour[x]; totBit *= bit[x];}
        ans = min(ans, abs(totSour - totBit));
        return;
    }
    comb(idx+1, id, res);
    res.push_back(id[idx]);
    comb(idx+1, id, res);
    res.pop_back;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> sour[i] >> bit[i]; id[i] = i;
    }
    comb(0, id, res);
}


/*
int taste(int &min, int s1, int b1, int s2, int b2) {
    int x = abs((s1*s2) - (b1+b2));
    if (x < min) {
        
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int min = INT_MAX;
    for (int i = 0; i < n; ++i) {
       if (abs(arr[i][0] - arr[i][1]) < min) {
           min = abs(arr[i][0] - arr[i][1]);
       }
    }

} */