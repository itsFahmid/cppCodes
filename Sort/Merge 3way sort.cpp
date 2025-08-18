#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid1, int mid2, int high) {
    vector<int> merged;
    int i = low, j = mid1 + 1, k = mid2 + 1;

    while (i <= mid1 || j <= mid2 || k <= high) {
        int val = INT_MAX;

        if (i <= mid1) val = min(val, arr[i]);
        if (j <= mid2) val = min(val, arr[j]);
        if (k <= high) val = min(val, arr[k]);

        if (i <= mid1 && arr[i] == val) merged.push_back(arr[i++]);
        else if (j <= mid2 && arr[j] == val) merged.push_back(arr[j++]);
        else if (k <= high && arr[k] == val) merged.push_back(arr[k++]);
    }

    for (int idx = 0; idx < merged.size(); ++idx)
        arr[low + idx] = merged[idx];
}

void threeWayMergeSort(vector<int>& arr, int low, int high) {
    if (low >= high)
        return;

    int third = (high - low) / 3;
    int mid1 = low + third;
    int mid2 = low + 2 * third + 1;

    if (mid2 > high) mid2 = high;  // Handle edge case

    threeWayMergeSort(arr, low, mid1);
    threeWayMergeSort(arr, mid1 + 1, mid2);
    threeWayMergeSort(arr, mid2 + 1, high);

    merge(arr, low, mid1, mid2, high);
}

int main() {
    vector<int> arr = {8, 3, 2, 9, 7, 1, 5, 4};
    threeWayMergeSort(arr, 0, arr.size() - 1);

    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}

