#include <bits/stdc++.h>
using namespace std;

bool bound(const vector<int> &table, int row, int col) {

    for(int i = 0; i < table.size(); ++i) {
        int curr_row = table[i];
        int curr_col = i + 1;

        if(abs(curr_row - row) == abs(curr_col - col)) {
            return false;
        }
    }
    return true; 
}

void testFunction(int coloumn, int n, vector<int>& table, vector<vector<int>>& result, vector<bool> &visited) {

    if(coloumn > n) {
        result.push_back(table);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) 
        {
            if(bound(table, i, coloumn)) 
            {
                visited[i] = true; 
                table.push_back(i); 
                testFunction(coloumn + 1, n, table, result, visited);

                table.pop_back(); 
                visited[i] = false;
            }
        }
    }
}

vector<vector<int>> placed_Queens(int n) 
{
    vector<vector<int>> result; 
    vector<int> table; 

    vector<bool> visited(n + 1, false); 

    testFunction(1, n, table, result, visited);
    return result; 
}

int main() {
    int n = 0;
    cout<<"Enter board size:- ";
    cin>>n;
    
    vector<vector<int>> result = placed_Queens(n); 

    for(auto &j : result) {
        cout << "[";
        for(int i = 0; i < n; ++i) {
            cout << j[i]; 
            if(i != n - 1) cout << ", "; 
        }
        cout << "]\n";
    }
    return 0;
}

