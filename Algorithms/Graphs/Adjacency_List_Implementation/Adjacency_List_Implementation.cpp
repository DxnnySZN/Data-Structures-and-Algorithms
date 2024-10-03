/* an array of lists is used. the size of an array is equal to the # of nodes.
   let the array be array[]. an entry array[i] represents the list of nodes adjacent to the ith node.
   
   Graph:     0--------------1
              |             /| \
              |          /   |    \   
              |       /      |      2
              |    /         |    /
              | /            | /
              4--------------3 */

#include <iostream>
#include <vector>

using namespace std;

// insert edge (u, v) in the adjacency list
void addEdge(vector<int> M[], int u, int v){
    M[u].push_back(v);
    M[v].push_back(u);
}

// prints adjacency list representation of graph
void printGraph(vector<int> M[], int nodeAmt){
    for(int i = 0; i < nodeAmt; ++i){
        cout << "\n Adjacency List of Node " << i << "\n" << "head";
        for(auto x: M[i]){ // looping through elements of the array and x represents the head that gets updated
            cout << " -> " << x;
        }
    }
    cout << endl;
}

int main() {
    const int nodeAmt = 5;
    vector<int> M[nodeAmt]; // adjacency list(array = list | M = vector of arrays)
    addEdge(M, 0, 1);
    addEdge(M, 0, 4);
    addEdge(M, 1, 2);
    addEdge(M, 1, 3);
    addEdge(M, 1, 4);
    addEdge(M, 2, 3);
    addEdge(M, 3, 4);
    printGraph(M, nodeAmt);
    return 0;

    /* Output: Adjacency List of Node 0
            head -> 1 -> 4
               Adjacency List of Node 1
            head -> 0 -> 2 -> 3 -> 4
               Adjacency List of Node 2
            head -> 1 -> 3
               Adjacency List of Node 3
            head -> 1 -> 2 -> 4
               Adjacency List of Node 4
            head -> 0 -> 1 -> 3 */
}