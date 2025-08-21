#include<bits/stdc++.h>
using namespace std;

vector<int> subset;

void searchh(int k, int n){
    if(k == n + 1){
        for(auto it : subset){
            cout << it << " ";
        }
        cout << endl;
    }
    else{
        subset.push_back(k);
        searchh(k + 1, n);
        subset.pop_back();
        searchh(k + 1, n);
    }
}

int main(){
    searchh(1, 3);      //declares the start and end of the set
}

// https://youtu.be/Y85dfkCSlP8
// this video contains good explanation
