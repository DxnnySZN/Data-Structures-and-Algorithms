#include <iostream>
#include <vector>

using namespace std;

int main(){
    int nodeAmt = 5;
    vector<vector<int>> A(nodeAmt, vector<int>(nodeAmt)); // nodeAmt -> row | vector<int>(nodeAmt) -> column
    int edgeAmt = 7;

    // fill the adjacency matrix
    for(int k = 0; k < edgeAmt; ++k){
        int u, v;
        cin >> u >> v;
        A[u][v] = 1;
        A[v][u] = 1;
    }

    for(int i = 0; i < nodeAmt; ++i){
        for(int j = 0; j < nodeAmt; ++j){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

    /* Notes:     Adjacency Matrix is a 2D vector/array of size n * n, where n is the number of nodes in a graph
                  Let the matrix be A[][]. A[i][j] = 1 indicates there is an edge from node i to node j
    
       Graph:     0--------------1
                  |             /| \
                  |          /   |    \   
                  |       /      |      2
                  |    /         |    /
                  | /            | /
                  4--------------3
    
       Test_Case: 0 1
                  0 4
                  1 4
                  1 3
                  3 4
                  1 2
                  2 3

       Output:    0 1 0 0 1 
                  1 0 1 1 1
                  0 1 0 1 0
                  0 1 1 0 1
                  1 1 0 1 0 */
}