#include <bits/stdc++.h>
using namespace std;
int R, C, N, col, num[102][102], idx[102];
bool cmp(int x, int y){ return num[x][col] < num[y][col]; }
int main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        idx[i] = i;
        for(int j=1; j<=C; j++)
            cin >> num[i][j];
    }
    for(cin>>N; N--; ){
        cin >> col; stable_sort(idx+1, idx+R+1, cmp);
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++)
            cout << num[idx[i]][j] << " ";
        cout << endl;
    }
}