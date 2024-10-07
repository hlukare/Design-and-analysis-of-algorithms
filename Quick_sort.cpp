#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &vector_array, int low, int high) {

    int pivot = vector_array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vector_array[j] <= pivot) {
            i++;
            swap(vector_array[i], vector_array[j]);
        }
    }
    swap(vector_array[i + 1], vector_array[high]);
    return (i + 1);
}

void quickSort(vector<int> &vector_array, int low, int high) {
    if (low < high) {
        int pi = partition(vector_array, low, high);
        quickSort(vector_array, low, pi - 1);
        quickSort(vector_array, pi + 1, high);
    }
}

int main() {
    int n=0;
    cout<<"Enter total no. of elements:- ";
    cin>>n;
    vector<int> vector_array(n);
    for(int i=0; i<n; i++){
        cin>>vector_array[i];
    }
    //int n = vector_array.size();
    quickSort(vector_array, 0, n - 1);

    for (auto i : vector_array) {
        cout << i << " ";
    }
    return 0;
}
