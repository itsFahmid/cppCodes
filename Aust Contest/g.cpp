#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, c = 0;
    cin >> n >> m >> x;
    vector<int> p(n), g(m);

    for(auto &it : p){
        cin >> it;
    }

    for(auto &it : g){
        cin >> it;
    }
    for(int it : p){
        for(int itt : g){
            if(it + itt <= x){
                c++;
            }
        }
    }
    cout << c << endl;
}
