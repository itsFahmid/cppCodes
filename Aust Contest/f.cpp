#include<bits/stdc++.h>
using namespace std;

int main(){
    bool flag = true;
    int n, k;
    cin >> n >> k;
    string s, l, r;
    cin >> s;
    for(int i=0; i<k; i++){
        if(flag){
            flag = false;
            swap(s[0], s[n - 1]);
            for(int j=0; j < (n / 2); j++){
                swap(s[j], s[(n / 2) + j]);
            }
        }
        else{
            flag = true;
            swap(s[n / 2], s[(n / 2) - 1]);
            reverse(s.begin(), s.end());
        }
    }
    cout << s << endl;
}
