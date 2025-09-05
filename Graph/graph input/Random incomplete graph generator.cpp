#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 50, c = n, x = 100, y = 150; // here, n is total number vertices, x and y is the limit within which the total number of edge will be.

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    uniform_int_distribution<> ed(x, y);
    uniform_int_distribution<> rand(0, 1);
    int e = ed(gen);
    bool flag = true;

    cout << n << " " << e << endl;
    for(int i=0; i<n; i++){ // to make sure the connectivity of the whole graph
        cout << i << " " << i+1 << " " << dist(gen) << endl;
    }
    while(c < e){
        for(int i=0; i<n; i++){
            for(int j = i + 2; j < n; j++){
                if(flag && (c < e)){
                    cout << i << " " << j << " " << dist(gen) << endl;
                    c++;
                }
                flag = rand(gen);
            }
        }
    }
}
