#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 10, y = 34;

    cout << x & y << "\n";

    for(int k = 31; k >= 0; k--){
        if(x & (1 << k)){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
}
