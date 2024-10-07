// Remember array to be sorted

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n=0, find=0;
    cout<<"Enter total number of elements:- ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:- ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"Enter the element to find:- ";
    cin>>find;
    int result = binarySearch(arr, 0, n - 1, find);
    if(result == -1)
    {
        cout << "Element is not present.";
    } 
    else
    {
        cout << "Element is present at index:- " << result;
    } 
    return 0;
}
