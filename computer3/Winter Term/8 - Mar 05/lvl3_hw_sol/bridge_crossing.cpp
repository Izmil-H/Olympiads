#include <iostream>
#include <string>
using namespace std;
string name[102];
int m, n, tim[102],best[102], group[102];
int main(){
	cin>>m>>n;
	for (int i = 0 ; i < n ; i++)
	    cin>>name[i]>>tim[i];
	for (int i = 1 ; i <= n; i++){
	    best [i] = 1000000; group [i] = -1;
	}
	best [0] = 0; group [0] = 0;
	for (int i = 0 ; i <= n ; i++){
	    int cur = 0;
	    for (int j = 1 ; j <= m && i + j - 1 < n ; j++){
            cur = max (cur, tim [i + j - 1]);
            if (best [i] + cur < best [i + j]){
                best [i + j] = best [i] + cur;
                group [i + j] = j;
            }
	    }
	}
    cout<<"Total Time: "<<best[n]<<endl;
	int lines[n+1], k = n, x = 0, z = 0;
	while (group [k] != 0){
	    lines [x++] = group [k];
	    k -= group [k];
	}
	for (int i = x - 1 ; i >= 0 ; i--){
	    for (int j = 0 ; j < lines [i] ; j++)
	        cout<<name[z++]<<" ";
	    cout<<endl;
	}
}