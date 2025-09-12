#include<bits/stdc++.h>
using namespace std;

int minCoinsRecur(int i, int sum, vector<int> &coins) {

    // base case
    if (sum == 0) return 0;
    if (sum <0 || i == coins.size()) return INT_MAX;

    int take = INT_MAX;

    // take a coin only if its value
    // is greater than 0.
    if (coins[i]>0) {
        take = minCoinsRecur(i, sum-coins[i], coins);
        if (take != INT_MAX) take++;
    }

    // not take the coin
    int noTake = minCoinsRecur(i+1, sum, coins);

    return min(take, noTake);
}

int minCoins(vector<int> &coins, int sum) {

   int res = minCoinsRecur(0, sum, coins);
   return res!=INT_MAX?res:-1;
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    int x;
    cin >> x;
    cout << minCoins(coins, x);
    return 0;
}
