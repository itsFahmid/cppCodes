#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &ve, int low, int high){
    int pivot = ve[high];
    int i = low - 1;

    for(int j=low; j <= high - 1; j++){
        if(ve[j] < pivot){
            i++;
            swap(ve[i], ve[j]);
        }
    }

    swap(ve[i + 1], ve[high]);
    return i + 1;
}

void quick_sort(vector<int> &ve, int low, int high){
    if(low < high){
        int pi = partition(ve, low, high);

        quick_sort(ve, low, pi - 1);
        quick_sort(ve, pi + 1, high);
    }
}

int main(){
    int n;
    cout << "Please input the size of an array: ";
    cin >> n;
    vector<int> ve(n);

    cout << "Please input the array elements: ";
    for(int &it : ve){
        cin >> it;
    }
    quick_sort(ve, 0, n - 1);

    for(int it : ve){
        cout << it << " ";
    }
}
