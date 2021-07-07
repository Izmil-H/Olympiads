#include<bits/stdc++.h>
using namespace std;

int main() {
    int time;
    cin >> time;
    
    cout << time << " in Ottawa\n";
    cout << (time-300 < 0? 2400+time-300: time-300) << " in Victoria\n"; // -3hrs
    cout << (time-200 < 0? 2400+time-200: time-200) << " in Edmonton\n"; // -2hrs
    cout << (time-100 < 0? 2400+time-100: time-100) << " in Winnipeg\n"; // -1hrs
    cout << time << " in Toronto\n"; // 0hrs
    cout << (time+100 >= 2400? time+100-2400: time+100) << " in Halifax\n"; // +1hrs
    cout << (time+130 >= 2400? time+130-2400: time+130) << " in St. John's\n"; // +1hr 30min
}