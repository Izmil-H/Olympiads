#include<bits/stdc++.h>
using namespace std; 

/*
IDEA: 
set array to t-m. Then add point to each winner. sruvivors have more than 0 points.
*/

/* --My attempt--
int main () {
    long n, t, m;
    cin >> n >> t >> m;
    long dif[n+2] = {0}; dif[0] = 3;
    
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        dif[0] -= 1; dif[a] += 1;
        dif[a+1] -= 1; dif[n+1] +=1;
    }
    long count = 0;
    for(int i = 1; i < n; i++) {
        dif[i] += dif[i-1];
        if (dif[i] > 0) count++;
    }
    cout << count;
}
*/

int main() {
    long n, t, m;
    cin >> n >> t >> m;
    int points[n] = {0};
    for(int i = 0; i < m; i++) {
        int a; cin >> a;
        points[a]++;
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        points[i] += t-m;
        if (points[i] > 0) count++;
    }
    cout << count;
}