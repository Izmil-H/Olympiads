#include<bits/stdc++.h>
using namespace std;

class cow{
    public:
    int id;
    char dir;
    int x;
    int y;
    int dist = 0;
    bool inf = false;
    int sX = x;
    int sY = y;
};

bool byPosition (cow a, cow b) {
    if (a.dir == b.dir) {
        if (a.dir == 'N') return a.x < b.x;
        return a.y < b.y;
    }
    return a.dir > b.dir;
}

bool byIndex (cow a, cow b) {
    return a.id < b.id;
}

int main() {
    int n; cin >> n;
    cow cows[n];
    for (int i = 0; i < n; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
        cows[i].dist = 0; cows[i].id = i;
    }
    sort(cows, cows+n, byPosition);
    for (int i = 0; i < n; i++) {
        
        if (cows[i].dir == 'N') {
            for(int j = 0; j < n; j++) {
                if (cows[j].dir == 'E' && cows[j].x < cows[i].x && cows[j].y > cows[i].y) {
                    cows[i].dist = cows[j].y - cows[i].y;

                    //cout << cows[j].x << ":" << cows[j].y << " " << cows[i].dist << endl;

                    if (cows[i].x - cows[j].x < cows[i].dist) {
                        cows[i].sY = cows[j].y; cows[j].sX = cows[i].x;
                        break;
                    }
                }
                if (j == n-1) cows[i].inf = true;
            }
            //cout << "***" << cows[i].dir << " " << cows[i].x << " " << cows[i].y << "**" << cows[i].dist << endl << endl;
        
        
        } else { // for eastward cows
            for(int j = 0; j < n; j++) {
                if (cows[j].dir == 'N' && cows[j].y < cows[i].y && cows[j].x > cows[i].x) {
                    cows[i].dist = cows[j].x - cows[i].x;

                    //cout << cows[j].x << ":" << cows[j].y << " " << cows[i].dist << " " << cows[i].y - cows[j].y << endl;
                   
                    if (cows[i].dist > cows[i].y - cows[j].y && cows[j].sY >= cows[i].y) {
                        //cout << "br" << endl;
                        //cout << cows[j].x << ":" << cows[j].y << " " << cows[i].dist << " " << cows[i].y - cows[j].y << endl;
                        break;
                    }
                }
                if (j == n-1) {
                    cows[i].inf = true; 
                    //cout << "br " << cows[i].inf << endl;
                }
            }
            //cout << "***" << cows[i].dir << " " << cows[i].x << " " << cows[i].y << "**" << cows[i].dist << endl << endl;
        }
    }
    sort(cows, cows+n, byIndex);
    for (int i = 0; i < n; i++) {
        if (cows[i].inf) cout << "Infinity";
        else cout << cows[i].dist;
        cout << endl;
    }
}