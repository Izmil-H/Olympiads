#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; string s;
    cin >> n >> s;
    int top = 0, bot = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'v') pos--;
        else if (s[i] == '^') pos++;
        if (pos > top) top = pos;
        if (pos < bot) bot = pos;
    }
    top++;

    int start = -bot; if (start != 0) start++; 
    cout << top << " " << bot << " " << start << endl;
    top -= bot; bot = 0;
    cout << top << " " << bot;

    char grid[top][n];
    for (int i = 0; i < top; i++) for (int j = 0; j < n; j++) grid[i][j] = '.';
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'v') {
            start--;
            grid[start][i] = '\\';
        } else if (s[i] == '^') {
            grid[start][i] = '/';
            start++;
        } else {
            grid[start][i] = '_';
            
        }
    }
   
    cout << endl;
    for (int i = top-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << "*";
            //cout << i << ":" << j << " ";
        }
    }
    cout << endl;
    for (int i = top-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}