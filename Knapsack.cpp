#include <bits/stdc++.h>
using namespace std;

int for_function(int W, int wt[], int val[], int index, int** arr) {
    if (index < 0)
        return 0;

    if (arr[index][W] != -1)
        return arr[index][W];

    if (wt[index] > W) 
    {
        arr[index][W] = for_function(W, wt, val, index - 1, arr);
        return arr[index][W];
    }
    else 
    {
        arr[index][W] = max(val[index] + for_function(W - wt[index], wt, val, index - 1, arr),
                           for_function(W, wt, val, index - 1, arr));
        return arr[index][W];
    }
}

int knapsack(int W, int wt[], int val[], int n, int selected[]) {

    int** arr;
    arr = new int*[n];

    for (int i = 0; i < n; i++)
        arr[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            arr[i][j] = -1;

    int temp = for_function(W, wt, val, n - 1, arr);

    int w1 = W;
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0) {
            if (arr[i][w1] != 0)
                selected[i] = 1;
        } else if (arr[i][w1] != arr[i - 1][w1]) {
            selected[i] = 1;
            w1 -= wt[i];
        } else {
            selected[i] = 0;
        }
    }
    return temp;
}

int main() {
    int n=0, W=0;
    cout<<"Enter total no. of items:- ";
    cin>>n;
    int profit[n];
    int weight[n];
    cout<<"Enter profits and weights of the items:- "<<endl;
    for(int i=0; i<n; i++){
        cout<<i+1<<":- ";
        cin>>profit[i];
        cout<<i+1<<":- ";
        cin>>weight[i];
        cout<<endl;
    }
    cout<<"Enter knapsack size:- ";
    cin>>W;
    //int n = sizeof(profit) / sizeof(profit[0]);
    
    int selected[n] = {0};
    
    int maxProfit = knapsack(W, weight, profit, n, selected);

    cout << "Maximum Profit: " << maxProfit << endl;
    cout << "Selected items (0/1): ";
    for (int i = 0; i < n; i++)
        cout << selected[i] << " ";
    cout << endl;

    return 0;
}
