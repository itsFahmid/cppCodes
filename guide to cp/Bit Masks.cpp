#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 10, y = 35;

    cout << (x & y) << "\n";    //Intersection
    cout << (x | y) << "\n";    //Union
    cout << (~x) << "\n";       //Compliment
    cout << (x & ~y) << "\n";   //Difference

    for(int k = 31; k >= 0; k--){
        if(x & (1 << k)){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << endl;
    for (int i = 0; i < 32; i++) {  //prints the elements present in x
        if (x&(1<<i)) cout << i << " ";
    }
    cout << endl;
    cout << __builtin_popcount(y) << "\n";  //number of 1 present in the bit sequence
}
