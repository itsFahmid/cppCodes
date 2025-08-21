#include<bits/stdc++.h>
using namespace std;

int n = 5;
int c = 0;
vector<bool> col(n, false), diag1(2*n, false), diag2(2*n, false);

void back_track_sol(int y){
    if(y == n){
        c++;
        return;
    }
    for(int x = 0; x < n; x++){
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        back_track_sol(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main(){
    back_track_sol(0);
    cout << c;
}
