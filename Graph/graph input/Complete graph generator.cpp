#include<bits/stdc++.h>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100); // random weight

    int n;
    cout << "Enter the amount of vertex: ";
    cin >> n;
    cout << endl << n << " " << (n * (n - 1) ) / 2 << endl;

    for(int i=0; i<n; i++){
        for(int j = i + 2; j < n; j++){
            cout << i << " " << j << " " << dist(gen) << endl;
        }
    }
}
