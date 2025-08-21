#include<bits/stdc++.h>
using namespace std;

int n = 4;
vector<int> permutation;
vector<bool> chosen(n + 1, false);

void searchh(){
    if(permutation.size() == n){
        for(auto it : permutation){
            cout << it << " ";
        }
        cout << endl;
    }
    else{
        for(int i=1; i<=n; i++){
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            searchh();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
    searchh();
}
