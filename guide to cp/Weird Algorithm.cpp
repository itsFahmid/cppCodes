#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; // it can't be an int type as it will have overflow problem causing the compiler to give time limit exceed or wrong answer
    cin >> n;
    while(1){
        cout << n << " ";
        if(n == 1) break;
        else if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
}
