#include<bits/stdc++.h>
using namespace std;

int binarySearchRec(vector<int> arr, int item, int low, int high){
    if(low <= high){
            int mid = low + (high - low) / 2;
        if(item == arr[mid]){
            return mid;
        }
        else if(item < arr[mid]){
            binarySearchRec(arr, item, low, mid - 1);
        }
        else{
            binarySearchRec(arr, item, mid + 1, high);
        }
    }
}

int binarySearchIter(vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &it : arr){
        cin >> it;
    }
    int item;
    cin >> item;
    cout << "Found at index: " << binarySearchIter(arr, item, 0, n - 1) + 1;
}
