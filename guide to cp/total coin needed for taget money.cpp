#include<bits/stdc++.h>
using namespace std;

/*
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
*/

#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int solveIter(int x, vector<int> &coins, vector<int> &value){
    value[0] = 0;
    for(int i = 1; i <= x; i++){
        for(auto c : coins){
            if(i - c  >= 0){
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }
    return value[x];
}

int solveRec(int x, vector<int> &coins, vector<bool> &ready, vector<int> &value){
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (ready[x]) return value[x];

    int best = INF;
    for (auto c : coins) {
        int res = solveRec(x - c, coins, ready, value);
        if (res != INF) best = min(best, res + 1); // avoid overflow
    }
    ready[x] = true;
    value[x] = best;
    return best;
}

int main(){
    int n;
    cout << "Enter the total number of coins: ";
    cin >> n;

    cout << "Enter the coins: ";
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter the total value to be produced: ";
    int x;
    cin >> x;

    vector<int> value(x + 1, INF);
    vector<bool> ready(x + 1, false);

    int ans = solveRec(x, coins, ready, value);
    int aans = solveIter(x, coins, value);

    cout << "recursive: " << endl;
    if (ans == INF) cout << "Not possible\n";
    else cout << "Minimum coins: " << ans << "\n";

    cout << "Iterative: " << endl;
    if (aans == INF) cout << "Not possible\n";
    else cout << "Minimum coins: " << aans << "\n";

    return 0;
}
