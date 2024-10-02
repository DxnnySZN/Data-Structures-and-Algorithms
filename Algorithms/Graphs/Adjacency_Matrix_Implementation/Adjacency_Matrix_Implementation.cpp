#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 5;
    vector<vector<int>> A(n, vector<int>(n)); // n -> row | vector<int>(n) -> column
    int edgeAmt = 7;

    // fill the adjacency matrix
    cout << "list the edges: " << endl;
    for(int k = 0; k < edgeAmt; ++k){
        int u, v;
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

    /* Test_Case:  
       Output: */
}