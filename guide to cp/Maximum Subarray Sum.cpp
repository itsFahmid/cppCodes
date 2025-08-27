// Given an array of n numbers, our first task is to calculate the maximum subarray sum, i.e., the largest possible sum of a sequence of consecutive values in the array.

#include<bits/stdc++.h>
using namespace std;

int worse(int arr[], int n){    // this computes O(n^3) time complexity
    int best = 0;
    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
        int sum = 0;
            for (int k = a; k <= b; k++) {
            sum += arr[k];
            }
        best = max(best,sum);
        }
    }
    return best;
}

int main(){
    int n = 5;
    int arr[n] = {1, 2, -3, 5, 4};

    cout << worse(arr, n) << "\n";
}
