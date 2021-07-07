#include<bits/stdc++.h>
using namespace std;

int main() {
    int time;
    cin >> time;

    cout <<  time                                 << " in Ottawa"     << endl
         << (time-300<0? 2100+time: time-300)     << " in Victoria"   << endl
         << (time-200<0? 2200+time: time-200)     << " in Edmonton"   << endl
         << (time-100<0? 2300+time: time-100)     << " in Winnipeg"   << endl
         <<  time                                 << " in Toronto"    << endl
         << (time+100>=2400? time-2300: time+100) << " in Halifax"    << endl
         << (time+130>2400? time-2270: time+130)  << " in St. John's" << endl;
}