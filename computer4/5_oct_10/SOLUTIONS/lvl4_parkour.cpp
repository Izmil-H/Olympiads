#include <bits/stdc++.h>
using namespace std;
int x, y, h, v, t, a, b;
//a: # of 2x moves   b: # of 2y moves
int main(){
    scanf("%d %d %d %d %d", &x, &y, &h, &v, &t);
    for(int i=0; i<t; i++) {
        a = (x-i)/2;
        b = y-2*i;
        int k = max(a, b), px = 2*k + i, py = k + 2*i;
        if(k + i < t && px >= x && px <= x+h && py >= y && py <= y + v) {
            printf("YES\n"); return 0;
        }
    }
    printf("NO\n");
}