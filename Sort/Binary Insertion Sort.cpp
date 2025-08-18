#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int item, int low, int high) {
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

void binaryInsertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int insertPos = binarySearch(arr, key, 0, i - 1);

        int j = i - 1;
        while (j >= insertPos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[insertPos] = key;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int &i : ve){
        cin >> i;
    }
    binaryInsertionSort(ve, n);
    for(int i : ve){
        cout << i << " ";
    }
    cout << endl;
}
