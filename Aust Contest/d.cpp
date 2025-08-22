#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<long long, long long> mp;
    vector<int> x;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1){
            int a, b;
            cin >> a >> b;
            if(mp[a] < b){
                mp[a] = b;
            }
        }
        else if(type == 2){
            int t;
            cin >> t;
            x.push_back(t);
        }
    }
    for(it : x){
        if(x )
    }
}


/*
6
1 10 100
1 8 80
1 10 120
2 9
2 10
2 5
*/
