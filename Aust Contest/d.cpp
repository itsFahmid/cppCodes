#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<long long, long long> mp;
    vector<long long> x;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1){
            long long a, b;
            cin >> a >> b;
            mp[a] = max(mp[a], b);
        }
        else if(type == 2){
            long long t;
            cin >> t;
            x.push_back(t);
        }
    }
    for(auto it : x){
        pair <long long, long long> res = {-1, -1};
        for(auto m : mp){
            if(m.first <= it){
                res.first = m.first;
                res.second = m.second;
            }
        }
        cout << res.first << " " << res.second << endl;
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
