#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3;
    vector<int> permutation;
    for(int i=1; i<=n; i++){
        permutation.push_back(i);
    }
    while( next_permutation(permutation.begin(), permutation.end()) ){  // this system will change the vector to next permutation and start after the default given vector
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
    do {
        for (int x : permutation) cout << x << " ";
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));     // this system will start with the default and then change the vector to next permutation
}
