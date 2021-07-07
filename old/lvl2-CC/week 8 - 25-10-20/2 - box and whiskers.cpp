#include<bits/stdc++.h>
using namespace std;

bool odd = false;

float median(float ar[], int size) {
//    cout << ar[0] << " - " << ar[size-1] << endl;
    if (size % 2 != 0)  {
        int idx = (size+1)/2 -1;
//        cout << "idx: " << idx << endl;
        return ar[idx];
    } else {
//        cout << "p1: " << ar[size/2-1] << " p2: " << ar[size/2] << endl;
        return (ar[size/2 -1] + ar[size/2])/2;
    }
}

int main() {
    int n;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    float q1, q2, q3;

//    cout << endl << "---Q2----" << endl;
    q2 = median(arr, n);
    
    int idx = ceil(q2) - 1;
    int siZe = idx;
    
//    cout << endl << "---Q1---" << endl;
    float subArr[idx];
    for (int i = 0; i < q2; ++i) {
        subArr[i] = arr[i];
    }
    q1 = median(subArr, siZe);

//    cout << endl << "---Q3---" << endl;
    float subArr2[idx];
    idx = int(q2) + 1;
//    cout << idx << " " << siZe << endl;
    for (int i = idx; i < n; ++i) {
        subArr2[i] = arr[i];
//        cout << subArr2[i] << " ";
    }

    q3 = median(subArr2, siZe);

    cout << arr[0] << " " << arr[n-1] << " "
         << setprecision(10) << q1 << " "
         << setprecision(10) << q2 << " "
         << setprecision(10) << q3 << endl;
    


    // 1 2 3 4 5 6 7 8 9 
    //   ^ ^   ^   ^ ^    

    // 1 2 3 4 5 : 6 7 8 9 10
    //     ^   ^   ^   ^    

    // 1 2 3 4 5 6 7 8 9 10 11
    //     ^     ^     ^       

    // 1 2 3 4 5 6 : 7 8 9 10 11 12
    //     ^ ^   ^   ^   ^ ^      
}